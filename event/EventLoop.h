/**
 * @file EventLoop.h
 * Contains the EventLoop class.
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
#ifndef SDL_EVENT_EVENTLOOP_H
#define SDL_EVENT_EVENTLOOP_H

#include "sdlpp/event/Dispatcher.h"
#include "sdlpp/event/Queue.h"

namespace sdl {
namespace event {
    /**
     * @struct EventLoop
     * @brief Represents an event loop.
     */
    struct EventLoop {
        /**
         * Handles events for the time remaining in the frame.
         *
         * @tparam Dispatcher The type of the Dispatcher through which to run events.
         *
         * @param dispatcher The Dispatcher through which to run events.
         * @param frameDelay The time slice for the frame.
         */
        template<class Dispatcher>
        static void run (Dispatcher& dispatcher, unsigned int frameDelay) {
            Queue& queue = Queue::instance ();
            unsigned int start = SDL_GetTicks ();
            while (SDL_GetTicks () - start < frameDelay) {
                if (!queue.empty ()) {
                    SDL_Event event = queue.pop ();
                    dispatcher (&event);
                }
            }
        }; 
    }; //EventLoop
}; //event
}; //sdl

#endif //SDL_EVENT_EVENTLOOP_H

