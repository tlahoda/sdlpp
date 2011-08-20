/**
 * @file Hat.h, Contains the basic_Hat and the Hat classes.
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
#ifndef SDL_DEVICES_HAT_H
#define SDL_DEVICES_HAT_H

namespace sdl {
namespace devices {
    /**
     * @struct basic_Hat, Base class for joystick hats.
     */
    struct basic_Hat {};

    /**
     * @struct Hat, Represents a joystick hat.
     *
     * @tparam Index, The index of the joystick.
     * @tparam Which, Which joystick Hat.
     */
    template<int Index, int Which>
    struct Hat : public basic_Hat {
        /**
         * Determines if the SDL_Event structure is for this Hat. 
         *
         * @param const SDL_Event* event, The SDL_Event to check.
         *
         * @return bool, true if the SDL_Event is for this Hat, false otherwise.
         */
        static bool equals (const SDL_Event* event) {
            return event->jhat.which == Index && event->jhat.hat == Which;
        };
    }; //Hat
}; //devices
}; //sdl

#endif //SDL_DEVICES_HAT_H

