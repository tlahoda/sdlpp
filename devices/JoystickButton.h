/**
 * @file JoystickButton.h, Contains the basic_JoystickButton and the JoystickButton classes.
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
#ifndef SDL_DEVICES_JOYSTICKBUTTON_H
#define SDL_DEVICES_JOYSTICKBUTTON_H

#include <boost/mpl/aux_/config/static_constant.hpp>

namespace sdl {
namespace devices {
    /**
     * @struct basic_JoystickButton, Base class for joystick buttons.
     */
    struct basic_JoystickButton {};

    /**
     * @struct JoystickButton, Represents a joystick button.
     *
     * @tparam Index, The index of the joystick.
     * @tparam Which, Which joystick button.
     */
    template<int Index, int Which>
    struct JoystickButton : public basic_JoystickButton {
        /**
         * The SDL_Event type check for JoystickButton press.
         */
        BOOST_STATIC_CONSTANT (int, pressed = SDL_JOYBUTTONDOWN);

        /**
         * The SDL_Event type check for JoystickButton release.
         */
        BOOST_STATIC_CONSTANT (int, released = SDL_JOYBUTTONUP);

        /**
         * Determines if the SDL_Event structure is for this JoystickButton. 
         *
         * @param const SDL_Event* event, The SDL_Event to check.
         *
         * @return bool, true if the SDL_Event is for this JoystickButton, false otherwise.
         */
        static bool equals (const SDL_Event* event) {
            return event->jbutton.which == Index && event->jbutton.button == Which;
        };
    }; //Button
}; //devices
}; //sdl

#endif //SDL_DEVICES_JOYSTICKBUTTON_H

