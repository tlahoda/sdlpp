/**
 * @file UserComparator.h, Contains the UserComparator class.
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
#ifndef SDL_EVENT_USERCOMPARATOR_H
#define SDL_EVENT_USERCOMPARATOR_H

#include <SDL.h>

namespace sdl {
namespace event {
    /**
     * struct UserComparator, Determines if the SDL_Event is the correct user event.
     *
     * @tparam Code, The code for the user event.
     */
    template<int Code>
    struct UserComparator {
        /**
         * Determines if the SDL_Event is the correct user event.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if the SDL_Event is the correct user event, false otherwise.
         */
        static bool compare (const SDL_Event* event) {
            return (event->type == SDL_USEREVENT) ? event->user.code == Code : false;
        };
    }; //UserComparator
}; //event
}; //sdl

#endif //SDL_EVENT_USERCOMPARATOR_H

