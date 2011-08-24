/**
 * @file Dispatcher.h
 * Contains the Adder and the Dispatcher classes.
 *
 * Copyright (C) 2005 Thomas P. Lahoda
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef SDL_EVENT_DISPATCHER_H
#define SDL_EVENT_DISPATCHER_H

#include <algorithm>

#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/mpl/for_each.hpp>

#include "sdlpp/event/Listener.h"

namespace sdl {
namespace event {
    using namespace boost;
    using namespace boost::mpl;

    /**
     * @struct Adder
     * @brief Adds a Listener for an event to a collection of Listeners.
     *
     * @tparam Listeners The type of the Listeners to which to add the Listener.
     * @tparam Handler The type of the Handler from which to get the Listener's handle function.
     */
    template<class Listeners, class Handler>
    struct Adder {
        /**
         * Constructs an Adder from a Listener and a Handler.
         *
         * @param listeners the Listeners to which to add the Listener.
         * @param handler the Handler from which to get the Listener's handle function.
         */
        Adder (Listeners& listeners, Handler& handler) : listeners_ (listeners), handler_ (handler) {};

        /**
         * Adds a listener for event to the Listeners.
         *
         * @tparam Event The type of the event for which to add a Listener.
         *
         * @param event The event for which to add a Listener.
         */
        template<class Event>
        void operator() (const Event& event) {
            listeners_.push_back (new Listener<Event, Handler> (handler_, &Handler::handle));
        };

        private:
            /**
             * The collection of Listeners to which to add Listeners.
             */
            Listeners& listeners_;

            /**
             * The Handler from which to get the Listener's handle functions.
             */
            Handler& handler_;
    }; //Adder

    /**
     * @class Dispatcher
     * @brief Dispatches events to Listeners.
     */
    class Dispatcher {
        public:
            /**
             * Constructs a default Dispatcher.
             */
            Dispatcher () : listeners_ () {};

            /**
             * Constructs a Dispatcher from a Handler.
             *
             * @tparam Handler The type of the Handler from which to construct the Dispatcher.
             *
             * @param handler The handler form which to get the Listener's handle functions.
             */
            template<class Handler>
            Dispatcher (Handler& handler) : listeners_ () { add (handler); };
    
            /**
             * Adds a handler to the Dispatcher.
             *
             * @tparam Handler The type of the Handler to add to the dispatcher.
             *
             * @param handler The Handler to add to the Dispatcher.
             *
             * @returns A reference to the Dispatcher.
             */
            template<class Handler>
            Dispatcher& add (Handler& handler) {
                boost::mpl::for_each<typename Handler::Events> (Adder<Listeners, Handler> (listeners_, handler));
                return *this;
            };

            /**
             * Dispatches an event.
             *
             * @param event The event to handle.
             */
            void operator() (const SDL_Event* event) {
                Listeners::iterator cur = std::find (listeners_.begin (), listeners_.end (), event);
                if (cur != listeners_.end ()) cur->operator() (event);
            };

        private:
            /**
             * Copy construct a Dispatcher.
             *
             * @param rhs The Dispatcher to copy.
             */
            Dispatcher (const Dispatcher& rhs);

            /**
             * The assignment operator.
             *
             * @param rhs the Dispatcher from which to assign.
             *
             * @return A reference to this Dispatcher.
             */
            Dispatcher& operator= (const Dispatcher& rhs);

            /**
             * @typedef boost::ptr_vector<basic_Listener> Listeners
             * @brief The type of the listeners.
             */
            typedef boost::ptr_vector<basic_Listener> Listeners;

            /**
             * The listeners.
             */
            Listeners listeners_;
    }; //Dispatcher
}; //event
}; //sdl

#endif //SDL_EVENT_DISPATCHER_H

