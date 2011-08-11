/**
 * @file Helpers.h, Contains the Moved, the Pressed, and the Released classes.
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
#ifndef SDL_EVENT_HELPERS_H
#define SDL_EVENT_HELPERS_H

namespace sdl {
namespace event {
    /**
     * @struct Moved, Expose the motion member of the device.
     */
    struct Moved {
        /**
         * Exposes the motion member of the device.
         *
         * @tparam Device, The device type.
         *
         * @param const Device& device, The device.
         *
         * @return int, The motion event type.
         */
        template<typename Device>
        static int eventType (const Device& device) {
            return Device::motion; 
        };
    }; //Moved

    /**
     * @struct Pressed, Exposes the pressed member of the device.
     */
    struct Pressed {
        /**
         * Exposes the pressed member of the device.
         *
         * @tparam Device, The device type.
         *
         * @param const Device& device, The device.
         *
         * @return int, The pressed event type.
         */
        template<typename Device>
        static int eventType (const Device& device) {
            return Device::pressed; 
        };
    }; //Pressed

    /**
     * @struct Released, Exposes the released member of the device.
     */
    struct Released {
        /**
         * Exposes the released member of the device.
         *
         * @tparam Device, The device type.
         *
         * @param const Device& device, The device.
         *
         * @return int, The released event type.
         */
        template<typename Device>
        static int eventType (const Device& device) {
            return Device::released; 
        };
    }; //Released
}; //event
}; //sdl

#endif //SDL_EVENT_HELPERS_H

