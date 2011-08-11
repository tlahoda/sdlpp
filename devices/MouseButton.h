/**
 * @file MouseButton.h, contains the basic_MouseButton and the MouseButton classes.
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
#ifndef SDL_DEVICES_MOUSEBUTTON_H
#define SDL_DEVICES_MOUSEBUTTON_H

#include <boost/mpl/aux_/config/static_constant.hpp>

namespace sdl {
namespace devices {
    /**
     * @struct basic_MouseButton, Base class for mouse buttons.
     */
    struct basic_MouseButton {};

    /**
     * @struct MouseButton, Represents a mouse button.
     *
     * @tparam Which, Which mouse button.
     */
    template<int Which>
    struct MouseButton : public basic_MouseButton {
        /**
         * The SDL_Event type for MouseButton press.
         */
        BOOST_STATIC_CONSTANT (int, pressed = SDL_MOUSEBUTTONDOWN);

        /**
         * The SDL_Event type check for MouseButton release.
         */
        BOOST_STATIC_CONSTANT (int, released = SDL_MOUSEBUTTONUP);

        /**
         * Determines if the SDL_Event structure is for this MouseButton. 
         *
         * @param const SDL_Event* event, The SDL_Event to check.
         *
         * @return bool, true if the SDL_Event is for this MouseButton, false otherwise.
         */
        static bool equals (const SDL_Event* event) {
            return event->button.button == Which;
        };
    }; //Button
}; //devices
}; //sdl

#endif //SDL_DEVICES_MOUSEBUTTON_H

