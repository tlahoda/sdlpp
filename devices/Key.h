/**
 * @file Key.h, Contains the basic_Key and the Key classes.
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
     * @struct basic_Key, Base class for keys.
     */
    struct basic_Key {};

    /**
     * @struct Key, Represents a key.
     *
     * @tparam Which, Which key.
     */
    template<int Which>
    struct Key : public basic_Key {
        /**
         * The SDL_Event type check for Key Press.
         */
        BOOST_STATIC_CONSTANT (int, pressed = SDL_KEYDOWN);

        /**
         * The SDL_Event type check for Key release.
         */
        BOOST_STATIC_CONSTANT (int, released = SDL_KEYUP);

        /**
         * Determines if the SDL_Event structure is for this Key. 
         *
         * @param const SDL_Event* event, The SDL_Event to check.
         *
         * @return bool, true if the SDL_Event is for this Key, false otherwise.
         */
        static bool equals (const SDL_Event* event) {
            return event->key.keysym.sym == Which;
        };
    }; //Key
}; //devices
}; //sdl

#endif //SDL_DEVICES_KEY_H

