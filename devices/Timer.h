/**
 * @file Timer.h, Contains the Timer class.
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
#ifndef SDL_DEVICES_TIMER_H
#define SDL_DEVICES_TIMER_H

#include <stdexcept>
#include <string>
#include <iostream>

#include <SDL.h>

#include "sdlpp/subsystem/Subsystem.h"

namespace sdl {
namespace devices {
    using namespace std;
    using namespace misc;

    /**
     * class Timer, Represents a timer.
     */
    class Timer {
        public:
            /**
             * @typedef unsigned int (*Callback) (unsigned int interval, void* param),
             *          The Timer callback declaration.
             *
             * @param unsigned int interval, The number of milliseconds to delay.
             * @param void* param, The callback's parameters.
             *
             * @return unsigned int, The next Timer interval.
             */
            typedef unsigned int (*Callback) (unsigned int interval, void* param);

            /**
             * Constructs a Timer.
             *
             * @param unsigned int interval, The number of milliseconds to delay.
             * @param Callback callback, The callback to call.
             * @param void* param, The callback's parameters.
             */
            Timer (unsigned int interval, Callback callback, void* param) 
              : id_ (add (interval, callback, param)) {
            };

            /**
             * Destroy the Timer.
             */
            ~Timer () { 
                //log error if unable to remove timer.
                if (SDL_RemoveTimer (id_) == SDL_FALSE)
                    cout << "Failed to remove timer " << id_ << endl;
            };

        private:
            /**
             * Copy constructs a Timer.
             *
             * @param const Timer& rhs, The Timer to copy.
             */
            Timer (const Timer& rhs);

            /**
             * The assignment operator
             *
             * @param const Timer& rhs, The Timer from which to assign.
             *
             * @return Timer&, A reference to this Timer.
             */
            Timer& operator= (const Timer& rhs);

            /**
             * Adds a timer which will call Callback are the specified number of milliseconds has elapsed.
             *
             * @param unsigned int interval, The number of milliseconds to delay.
             * @param Callback callback, The callback to call.
             * @param void* param, The callback's parameters.
             *
             * @return SDL_TimerID, The id of the added timer.
             */
            SDL_TimerID add (unsigned int interval, Callback callback, void* param) {
                subsystem::Timer::instance ();
                SDL_TimerID id = SDL_AddTimer (interval, callback, param);
                if (id == NULL)
                    throw runtime_error ("Failed to add timer.");
                return id;
            };

            /**
             * The id of the timer.
             */
            SDL_TimerID id_;
    }; //Timer
}; //devices
}; //sdl

#endif //SDL_DEVICES_TIMER_H

