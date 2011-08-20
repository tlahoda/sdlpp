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
     * @tparam EventTypeGetter, Gets the specific event type.
     * @tparam Devices, The list of Devices.
     */
    template<typename Device, typename EventTypeGetter, int... Ts>
    struct MultiComparator {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correc tfor the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) { return false; };
    }; //MultiComparator

    /**
     * @struct MultiComparator, The recursion's terminal specialization.
     *
     * @tparam EventTypeGetter, Gets the specific event type.
     */
    template<typename Device, typename EventTypeGetter>
    struct MultiComparator<Device, EventTypeGetter> {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correc tfor the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) { return false; };
    }; //MultiComparator

    /**
     * @struct MultiComparator, The main specialization that recurses through the Devices comparing them to the SDL_Event structure.
     *
     * @tparam EventTypeGetter, Gets the specific event type from the Device.
     * @tparam Device, The Device to check.
     * @tparam Devices, The list of Devices.
     */
    template<typename Device, typename EventTypeGetter, int T, int... Ts>
    struct MultiComparator<Device, EventTypeGetter, T, Ts...> {
        /**
         * Determines if the SDL_Event structure is correct for the devices.
         *
         * @param const SDL_Event* event, The SDL_Event structure to check.
         *
         * @return bool, True if any of the devices are correc tfor the SDL_Event structure.
         */
        static bool compare (const SDL_Event* event) {
            Device device (T);
            return (EventTypeGetter::eventType (device) == event->type && device == event) || MultiComparator<Device, EventTypeGetter, Ts...>::compare (event);
        };
    }; //MultiComparator
}; //event
}; //sdl

#endif //SDL_EVENT_MULTICOMPARATOR_H

