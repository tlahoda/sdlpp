/**
 * @file UserEvent.h, Contains the user event classes.
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
#ifndef SDL_EVENT_USEREVENT_H
#define SDL_EVENT_USEREVENT_H

#include <SDL.h>

#include "sdlpp/event/UserComparator.h"
#include "sdlpp/event/Event.h"

namespace sdl {
namespace event {
    /**
     * @struct UserBase, Base for user events that exposes the SDL_UserEvent structure.
     */
    struct UserBase : public EventBase {
        /**
         * Constructs a UserBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        UserBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_UserEvent structure.
         *
         * @return const SDL_UserEvent&, The SDL_UserEvent structure.
         */
        const SDL_UserEvent& get () const { return event_->user; };
    
        /**
         * Exposes the SDL_UserEvent structure.
         *
         * @return const SDL_UserEvent&, The SDL_UserEvent structure.
         */
        const SDL_UserEvent& get () { return event_->user; };
    }; //UserBase

    /**
     * @struct User, Represents a user event.
     *
     * @tparam Code, The specific user event code.
     */
    template<int Code>
    struct User : public Event<UserComparator<Code>, UserBase> {
        /**
         * Constructs a UserEvent from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit User (const SDL_Event* event = 0) : Event<UserComparator<Code>, UserBase> (event) {};
    }; //User
}; //event
}; //sdl

#endif //SDL_EVENT_USEREVENT_H

