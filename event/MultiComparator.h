/**
 * @file MultiComparator.h, Contains the MultiComparator class.
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
#ifndef SDL_EVENT_MULTICOMPARATOR_H
#define SDL_EVENT_MULTICOMPARATOR_H

#include <SDL.h>

namespace sdl {
namespace event {
    /**
     * @struct MultiComparator, Recurse through the Device list checking to see if the SDL_Event structure is correct for any of them.
     *
     * @tparam Device, The type of device being compared.
     * @tparam EventType, The specific event type.
     * @tparam Ids, The list of Devices ids.
     */
    template<typename Device, int EventType, int... Ids>
    struct MultiComparator {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correct for the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) { return false; };
    }; //MultiComparator

    /**
     * @struct MultiComparator, The recursion's terminal specialization.
     *
     * @tparam Device, The type of device being compared.
     * @tparam EventType, The specific event type.
     */
    template<typename Device, int EventType>
    struct MultiComparator<Device, EventType> {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correct for the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) { return false; };
    }; //MultiComparator

    /**
     * @struct MultiComparator, The main specialization that recurses through the Devices comparing them to the SDL_Event structure.
     *
     * @tparam Device, The type of device being compared.
     * @tparam EventType, The specific event type.
     * @tparam Device, The Device to check.
     * @tparam Devices, The list of Devices.
     */
    template<typename Device, int EventType, int T, int... Ts>
    struct MultiComparator<Device, EventType, T, Ts...> {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correct for the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) {
            return (EventType == event->type && Device::which (event) == T) || MultiComparator<Device, EventType, Ts...>::compare (event);
        };
    }; //MultiComparator
}; //event
}; //sdl

#endif //SDL_EVENT_MULTICOMPARATOR_H

