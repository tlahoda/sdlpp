/**
 * @file Event.h, Contains the EventBase and the  Event classes.
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
#ifndef SDL_EVENT_EVENT_H
#define SDL_EVENT_EVENT_H

#include <stdexcept>

#include <SDL.h>

namespace sdl {
namespace event {
    using namespace misc;

    /**
     * @struct EventBase, Base for events that holds a SDL_Event structure.
     */
    struct EventBase {
        /**
         * Constructs an EventBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        EventBase (const SDL_Event* event) : event_ (event) {};

        protected:
            /**
             * The SDL_Event structure held.
             */
            const SDL_Event* event_;
    }; //EventBase

    /**
     * @struct Event, Represents an event.
     *
     * @tparam Comparator, Ensures the correctness of the SDL_Event structure.
     * @tparam Base, The Base type of the event.
     */
    template<typename Comparator, typename Base>
    struct Event : public Base {
        /**
         * Determines if the SDL_Event structure is correct for this event.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if the SDL_Event structure is correct, false otherwise.
         */
        static bool is (const SDL_Event* event) { return Comparator::compare (event); };

        /**
         * Constructs an event from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         *
         * @throw runtime_error, Throws a runtime_error if the event type in incorrect.
         */
        explicit Event (const SDL_Event* event = 0) : Base (event) {
            if (event != 0)
                if (!is (event)) throw std::runtime_error ("Mismatch");
        };
    }; //Event
}; //event
}; //sdl

#endif //SDL_EVENT_EVENT_H

