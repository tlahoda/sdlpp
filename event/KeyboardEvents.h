/**
 * @file KeyboardEvents.h, Contains the keyboard event classes. 
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
#ifndef SDL_EVENT_KEYBOARDEVENTS_H
#define SDL_EVENT_KEYBOARDEVENTS_H

#include <SDL.h>

#include "sdlpp/devices/Key.h"
#include "sdlpp/event/Helpers.h"
#include "sdlpp/event/MultiComparator.h"
#include "sdlpp/event/SimpleComparator.h"
#include "sdlpp/event/Event.h"

namespace sdl {
namespace event {
    using namespace devices;
    using namespace misc;

    /**
     * @struct KeyBase, Base for keyboard events that exposes the SDL_KeyboardEvent structure.
     */
    struct KeyBase : public EventBase {
        /**
         * Constructs an KeyBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        KeyBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_KeyboardEvent structure.
         *
         * @return const SDL_KeyboardEvent&, The SDL_KeyboardEvent structure.
         */
        const SDL_KeyboardEvent& get () const { return event_->key; };

        /**
         * Exposes the SDL_KeyboardEvent structure.
         *
         * @return const SDL_KeyboardEvent&, The SDL_KeyboardEvent structure.
         */
        const SDL_KeyboardEvent& get () { return event_->key; };
    }; //KeyBase

    /**
     * @struct KeyPress, Represents a key press event.
     *
     * @tparam Keys, The keys that compose this key press event.
     */
    template<int... Keys>
    struct KeyPress : public Event<MultiComparator<Key, Pressed, Keys...>, KeyBase> {
        /**
         * Constructs a KeyPress event from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit KeyPress (const SDL_Event* event = 0) : Event<MultiComparator<Key, Pressed, Keys...>, KeyBase> (event) {};
    }; //KeyPress

    /**
     * @typedef Event<SimpleComparator<SDL_KEYDOWN>, KeyBase> AnyKeyPress,
     *          Represents an any key press.
     */
    typedef Event<SimpleComparator<SDL_KEYDOWN>, KeyBase> AnyKeyPress;
    
    /**
     * @struct KeyRelease, Represents a key release event.
     *
     * @tparam Keys, The keys that compose this key release event.
     */
    template<int... Keys>
    struct KeyRelease : public Event<MultiComparator<Key, Released, Keys...>, KeyBase> {
        /**
         * Constructs a KeyRelease from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit KeyRelease (const SDL_Event* event = 0) : Event<MultiComparator<Key, Released, Keys...>, KeyBase> (event) {};
    }; //KeyRelease

    /**
     * @typedef Event<SimpleComparator<SDL_KEYUP>, KeyBase> AnyKeyRelease,
     *          Represents an any key release event.
     */
    typedef Event<SimpleComparator<SDL_KEYUP>, KeyBase> AnyKeyRelease;
}; //event
}; //sdl

#endif //SDL_EVENT_KEYBOARDEVENTS_H

