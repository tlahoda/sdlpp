/**
 * @file Queue.h, Contains the event Queue class.
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
#ifndef SDL_EVENT_QUEUE_H
#define SDL_EVENT_QUEUE_H

#include <SDL.h>

namespace sdl {
namespace event {
    using namespace std;

    /**
     * @class Queue, The event queue.
     */
    class Queue {
        public:
            /*
             * Provides access to the Queue.
             *
             * return Queue&, A reference to the Queue.
             */
            static Queue& instance () {
                static Queue instance_;
                return instance_;
            };

            /*
             * Determines whether or not the Queue is empty.
             *
             * @return bool, True if the queue is empty, false otherwise.
             */
            bool empty () {
                return !SDL_PollEvent (0);
            };

            /*
             * Removes an event from the front of the Queue.
             *
             * @return SDL_Event, The event at the front of the queue.
             */
            SDL_Event pop () {
                SDL_Event event;
                if (!SDL_PollEvent (&event)) throw runtime_error ("No events in queue.");
                return event;
            };

            /*
             * Pushes an event onto the back of the Queue.
             *
             * @param SDL_Event& event, The event to push onto the Queue.
             *
             * @return bool, True if the event was pushed onto the Queue, false otherwise.
             */
            bool push (SDL_Event& event) {
                return SDL_PushEvent (&event);
            };

            /*
             * Pumps the Queue.
             *
             * @return Queue&, A reference to the Queue.
             */
            Queue& pump () {
                SDL_PumpEvents ();
                return *this;
            };

            /*
             * Waits on an event to become available in the Queue.
             *
             * @return SDL_Event, The event returned at the end of the wait.
             */
            SDL_Event wait () {
                SDL_Event event;
                if (!SDL_WaitEvent (&event)) throw runtime_error ("An error occured while waiting for event.");
                return event;
            };

        private:
            /*
             * Constructs a Queue.
             */
            Queue () {
            };

            /*
             * Copy constructs a Queue.
             *
             * @param const Queue& rhs, The Queue to copy.
             */
            Queue (const Queue& rhs);

            /*
             * Destroys a Queue.
             */
            ~Queue () {
            };

            /*
             * The Assignment Operator.
             *
             * @param const Queue& rhs, The Queue from which to assign.
             *
             * @return Queue&, A reference to this Queue.
             */
            Queue& operator= (const Queue& rhs);
    }; //Queue
}; //event
}; //sdl

#endif //SDL_EVENT_QUEUE_H

