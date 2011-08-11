/**
 * @file Axis.h, Contains the basic_Axis and the Axis classes.
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
#ifndef SDL_DEVICES_AXIS_H
#define SDL_DEVICES_AXIS_H

#include <boost/mpl/aux_/config/static_constant.hpp>

namespace sdl {
namespace devices {
    /**
     * @struct basic_Axis, Base class for joystick axes.
     */
    struct basic_Axis {};

    /**
     * @struct Axis, Represents a joystick axis.
     *
     * @tparam Index, The index of the joystick.
     * @tparam Which, Which joystick axis.
     */
    template<int Index, int Which>
    struct Axis : public basic_Axis {
        /**
         * The SDL_Event type check for Axis motion.
         */
        BOOST_STATIC_CONSTANT (int, motion = SDL_JOYAXISMOTION);

        /**
         * Determines if the SDL_Event structure is for this Axis. 
         *
         * @param const SDL_Event* event, The SDL_Event to check.
         *
         * @return bool, true if the SDL_Event is for this Axis, false otherwise.
         */
        static bool equals (const SDL_Event* event) {
            return event->jaxis.which == Index && event->jaxis.axis == Which;
        };
    };//Axis
}; //devices
}; //sdl

#endif //SDL_DEVICES_AXIS_H

