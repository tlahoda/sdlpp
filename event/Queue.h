/**
 * @file Queue.h
 * Contains the event Queue class.
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
     * @class Queue
     * @brief The event queue.
     */
    class Queue {
        public:
            /**
             * @typedef int (*EventFilter) (const SDL_Event* event),
             * @brief The type of the event filter function
             *
             * @param event The event to filter.
             *
             * @return 1 to add the event to the queue, 0 to drop the event from the queue.
             */
            typedef int (*EventFilter) (const SDL_Event* event);

            /*
             * Provides access to the Queue.
             *
             * @return A reference to the Queue.
             */
            static Queue& instance () {
                static Queue instance_;
                return instance_;
            };

            /**
             * Sets the event filter function.
             *
             * @param filter The pointer to the event filter function.
             */
            void SetFilter (EventFilter filter) { SDL_SetEventFilter (filter); };

            /**
             * Returns the pointer to the event filter function.
             *
             * @return The pointer to the event filter function.
             */
            EventFilter getFilter () { return SDL_GetEventFilter (); };

            /**
             * Returns the processing state of the specified event type.
             *
             * @param type The event type.
             *
             * @return The event state.
             */
            int getEventState (int type) { return SDL_EventState (type, SDL_QUERY); };

            /*
             * Ignores a specific event.
             *
             * @param type The type of the event to ignore.
             *
             * @return no idea.
             */
            int ignoreEvent (int type) { return SDL_EventState (type, SDL_IGNORE); };
            
            /**
             * Disables a specific event.
             *
             * @param type The type of the event to disable.
             *
             * @return no idea.
             */
            int disableEvent (int type) { return SDL_EventState (type, SDL_DISABLE); };

            /**
             * Enables a specific event.
             *
             * @param type The type of the event to enable.
             *
             * @return no idea.
             */
            int enableEvent (int type) { return SDL_EventState (type, SDL_ENABLE); };

            /*
             * Determines whether or not the Queue is empty.
             *
             * @return True if the queue is empty, false otherwise.
             */
            bool empty () { return !SDL_PollEvent (0); };

            /*
             * Removes an event from the front of the Queue.
             *
             * @return The event at the front of the queue.
             *
             * @throw runtime_error Throws a runtime_error if no events in queue.
             */
            SDL_Event pop () {
                SDL_Event event;
                if (!SDL_PollEvent (&event)) throw runtime_error ("No events in queue.");
                return event;
            };

            /*
             * Pushes an event onto the back of the Queue.
             *
             * @param event The event to push onto the Queue.
             *
             * @return True if the event was pushed onto the Queue, false otherwise.
             */
            bool push (SDL_Event& event) { return SDL_PushEvent (&event); };

            /*
             * Pumps the Queue.
             *
             * @return A reference to the Queue.
             */
            Queue& pump () {
                SDL_PumpEvents ();
                return *this;
            };

            /*
             * Waits on an event to become available in the Queue.
             *
             * @return The event returned at the end of the wait.
             *
             * @throw runtime_error Throws a runtime_error if failed waiting.
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
            Queue () {};

            /*
             * Copy constructs a Queue.
             *
             * @param rhs The Queue to copy.
             */
            Queue (const Queue& rhs);

            /*
             * Destroys a Queue.
             */
            ~Queue () {};

            /*
             * The assignment operator.
             *
             * @param rhs The Queue from which to assign.
             *
             * @return A reference to this Queue.
             */
            Queue& operator= (const Queue& rhs);
    }; //Queue
}; //event
}; //sdl

#endif //SDL_EVENT_QUEUE_H

