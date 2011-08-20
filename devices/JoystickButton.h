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

namespace sdl {
namespace devices {
    /**
     * @struct JoystickButton, Represents a joystick button.
     */
    struct JoystickButton {
        explicit JoystickButton (int which) : which_ (which) {};

        /**
         * Determines if the SDL_Event structure is for this JoystickButton. 
         *
         * @param const SDL_Event* event, The SDL_Event to check.
         *
         * @return bool, true if the SDL_Event is for this JoystickButton, false otherwise.
         */
        bool operator== (const SDL_Event* event) {
            return event->jbutton.button == which_;
        };

        private:
            int which_;
    }; //Button
}; //devices
}; //sdl

#endif //SDL_DEVICES_JOYSTICKBUTTON_H

