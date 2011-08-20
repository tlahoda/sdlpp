/**
 * @file Key.h, Contains the Key class.
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
#ifndef SDL_DEVICES_KEY_H
#define SDL_DEVICES_KEY_H

#include <boost/mpl/aux_/config/static_constant.hpp>

namespace sdl {
namespace devices {
    /**
     * @struct Key, Represents a key.
     *
     * @tparam Which, Which key.
     */
    struct Key {
        /**
         * The SDL_Event type check for Key Press.
         */
        BOOST_STATIC_CONSTANT (int, pressed = SDL_KEYDOWN);

        /**
         * The SDL_Event type check for Key release.
         */
        BOOST_STATIC_CONSTANT (int, released = SDL_KEYUP);

        explicit Key (int which) : which_ (which) {};

        /**
         * Determines if the SDL_Event structure is for this Key. 
         *
         * @param const SDL_Event* event, The SDL_Event to check.
         *
         * @return bool, true if the SDL_Event is for this Key, false otherwise.
         */
        bool operator== (const SDL_Event* event) {
            return event->key.keysym.sym == which_;
        };

        private:
            int which_;
    }; //Key
}; //devices
}; //sdl

#endif //SDL_DEVICES_KEY_H

