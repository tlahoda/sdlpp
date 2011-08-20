/**
 * @file JoystickComparator.h, Contains the JoystickComparator class.
 *
 * Copyright (C) 2011 Thomas P. Lahoda
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
#ifndef SDL_EVENT_JOYSTICKCOMPARATOR_H
#define SDL_EVENT_JOYSTICKCOMPARATOR_H

#include <SDL.h>

namespace sdl {
namespace event {
    /**
     * @struct JoystickComparator, Recurse through the Device list checking to see if the SDL_Event structure is correct for any of them.
     *
     * @tparam EventTypeGetter, Gets the specific event type.
     * @tparam Devices, The list of Devices.
     */
    template<typename EventTypeGetter, int... Devices>
    struct JoystickComparator {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correc tfor the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) { return false; };
    }; //JoystickComparator

    /**
     * @struct JoystickComparator, The recursion's terminal specialization.
     *
     * @tparam EventTypeGetter, Gets the specific event type.
     */
    template<typename EventTypeGetter>
    struct JoystickComparator<EventTypeGetter> {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correc tfor the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) { return false; };
    }; //JoystickComparator

    /**
     * @struct JoystickComparator, The main specialization that recurses through the Devices comparing them to the SDL_Event structure.
     *
     * @tparam EventTypeGetter, Gets the specific event type from the Device.
     * @tparam Device, The Device to check.
     * @tparam Devices, The list of Devices.
     */
    template<typename EventTypeGetter, int Device, int... Devices>
    struct JoystickComparator<EventTypeGetter, Device, Devices...> {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correc tfor the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) {
            Device device;
            return (EventTypeGetter::eventType (device) == event->type && Device::equals (event)) || JoystickComparator<EventTypeGetter, Devices...>::compare (event);
        };
    }; //JoystickComparator
}; //event
}; //sdl

#endif //SDL_EVENT_JOYSTICKCOMPARATOR_H

