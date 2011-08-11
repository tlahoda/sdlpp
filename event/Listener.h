/**
 * @file Listener.h, Contains the basic_Listener and the Listener classes.
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
#ifndef SDL_EVENT_LISTENER_H
#define SDL_EVENT_LISTENER_H

#include <iostream>

#include <SDL.h>

namespace sdl {
namespace event {
    /**
     * @class basic_Listener, Base Listener class.
     */
    class basic_Listener {
        public:
            /**
             * Destroys the basic_Listener.
             */
            virtual ~basic_Listener () {
            };

            /**
             * Determines if a basic_Listener equates to a SDL_Event.
             *
             * @param const SDL_Event* event, The SDL_Event to check.
             *
             * @return bool, True if the SDL_Event equates to the basic_Listener, false otherwise.
             */
            virtual bool operator== (const SDL_Event* event) { 
                return false; 
            };

            /**
             * Handles an event.
             *
             * @param const SDL_Event* event, The event to handle.
             *
             * @return bool, True if the event was handled, false otherwise.
             */
            virtual bool operator() (const SDL_Event* event) = 0;
    }; //basic_Listener

    /**
     * @class Listener, Listens for and handles an event.
     *
     * @tparam EventType, The type of the event for which to listen.
     * @tparam Handler, The Handler to handle the event.
     */
    template<class EventType, class Handler>
    class Listener : public basic_Listener {
        public:
            /**
             * @typedef bool (Handler::*HandleFunc) (const EventType& event),
             *          The member function pointer to the Handler's handle function.
             *
             * @param const EventType& event, The event to handle.
             *
             * @return bool, True if the event was handled, false otherwise.
             */
            typedef bool (Handler::*HandleFunc) (const EventType& event);

            /**
             * Determines if a Listener equates to an SDL_Event.
             *
             * @param const SDL_Event* event, The SDL_Event to check.
             *
             * @return bool, True if the SDL_Event equates to the Listener, false otherwise.
             */
            virtual bool operator== (const SDL_Event* event) { 
                return EventType::is (event); 
            };

            /**
             * Constructs a Listener for a Handler's handle function.
             *
             * @param Handler& h, The Handler to handle the event.
             * @param HandleFunc func, The Handler's handle function for the event.
             */
            Listener (Handler& h, HandleFunc func)
              : basic_Listener (), h_ (h), func_ (func) {
            }; 

            /**
             * Destroys the Listener.
             */
            virtual ~Listener () {
            };

            /**
             * Handles an event.
             *
             * @param const SDL_Event& event, the event to handle.
             *
             * @return bool, true if the event was handled, false otherwise.
             */
            virtual bool operator() (const SDL_Event* event) {
              return (h_.*func_) (EventType (event));
            };

        private:
            /**
             * The Handler to handle the event.
             */
            Handler& h_;

            /**
             * The Handler's handle function for the event.
             */
            HandleFunc func_;
    }; //Listener
}; //event
}; //sdl

#endif //SDL_EVENT_LISTENER_H

