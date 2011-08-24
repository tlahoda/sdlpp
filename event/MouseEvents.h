/**
 * @file MouseEvents.h
 * Contains the mouse events classes.
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
#ifndef SDL_EVENT_MOUSEEVENTS_H
#define SDL_EVENT_MOUSEEVENTS_H

#include <SDL.h>

#include "sdlpp/event/Components.h"
#include "sdlpp/event/MultiComparator.h"
#include "sdlpp/event/SimpleComparator.h"
#include "sdlpp/event/Event.h"

namespace sdl {
namespace event {
    using namespace misc;

   /**
     * @struct MouseMotionBase
     * @brief Base for mouse motion events that exposes the SDL_MouseMotionEvent structure.
     */
    struct MouseMotionBase : public EventBase {
        /**
         * Constructs a MouseMotionBase from a SDL_Event structure.
         *
         * @param event The SDL_Event structure.
         */
        MouseMotionBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_MouseMotionEvent structure.
         *
         * @return The SDL_MouseMotionEvent structure.
         */
        const SDL_MouseMotionEvent& get () const { return event_->motion; }; 

        /**
         * Exposes the SDL_MouseMotionEvent structure.
         *
         * @return The SDL_MouseMotionEvent structure.
         */
        const SDL_MouseMotionEvent& get () { return event_->motion; };
    }; //MouseMotion
    
    /**
     * @typedef Event<SimpleComparator<SDL_MOUSEMOTION>, MouseMotionBase> MouseMotion
     * @brief Represents a mouse motion event.
     */
    typedef Event<SimpleComparator<SDL_MOUSEMOTION>, MouseMotionBase> MouseMotion;

    /**
     * @struct MouseButtonBase
     * @brief Base for mouse button events that exposes the SDL_MouseButtonEvent structure.
     */
    struct MouseButtonBase : public EventBase {
        /**
         * Constructs a MouseButtonBase from a SDL_Event*.
         *
         * @param event The SDL_Event structure.
         */
        MouseButtonBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_MouseButtonEvent structure.
         *
         * @return The SDL_MouseButtonEvent structure.
         */
        const SDL_MouseButtonEvent& get () const { return event_->button; };

        /**
         * Exposes the SDL_MouseButtonEvent structure.
         *
         * @return The SDL_MouseButtonEvent structure.
         */
        const SDL_MouseButtonEvent& get () { return event_->button; };
    }; //MouseButtonBase

    /**
     * @struct MouseButtonPress, Represents a mouse button press event.
     *
     * @tparam Buttons The buttons that compose this mouse button release event.
     */
    template<int... Buttons>
    struct MouseButtonPress : public Event<MultiComparator<MouseButton, SDL_MOUSEBUTTONDOWN, Buttons...>, MouseButtonBase> {
        /**
         * Constructs a MouseButtonPress from a SDL_Event structure.
         *
         * @param event The SDL_Event structure.
         */
        explicit MouseButtonPress (const SDL_Event* event = 0) : Event<MultiComparator<MouseButton, SDL_MOUSEBUTTONDOWN, Buttons...>, MouseButtonBase> (event) {};
    }; //MouseButtonPress

    /**
     * @struct MouseButtonRelease, Represents a mouse button release event.
     *
     * @tparam Buttons The buttons that compose this mouse button release event.
     */
    template<int... Buttons>
    struct MouseButtonRelease : public Event<MultiComparator<MouseButton, SDL_MOUSEBUTTONUP, Buttons...>, MouseButtonBase> {
        /**
         * Constructs a MouseButtonRelease from a SDL_Event structure.
         *
         * @param event The SDL_Event structure.
         */
        explicit MouseButtonRelease (const SDL_Event* event = 0) : Event<MultiComparator<MouseButton, SDL_MOUSEBUTTONUP, Buttons...>, MouseButtonBase> (event) {};
    }; //MouseButtonRelease
}; //event
}; //sdl

#endif //SDL_EVENT_MOUSEEVENTS_H

