/**
 * @file Components.h, Contains the Axis, Hat, JoystickButton, Key, Mousebutton, Trackball, and User classes.
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
#ifndef SDL_EVENT_COMPONENTS_H
#define SDL_EVENT_COMPONENTS_H

namespace sdl {
namespace event {
    /**
     * @struct Axis, Represents a joystick axis.
     */
    struct Axis {
        static int which (const SDL_Event* event) { return event->jaxis.axis; };
    };//Axis

    /**
     * @struct Hat, Represents a joystick hat.
     */
    struct Hat {
        static int which (const SDL_Event* event) { return event->jhat.hat; };
    }; //Hat
    
    /**
     * @struct JoystickButton, Represents a joystick button.
     */
    struct JoystickButton {
        static int which (const SDL_Event* event) { return event->jbutton.button; };
    }; //Button

    /**
     * @struct Key, Represents a key.
     */
    struct Key {
        static int which (const SDL_Event* event) { return event->key.keysym.sym; };
    }; //Key

    /**
     * @struct MouseButton, Represents a mouse button.
     */
    struct MouseButton {
        static int which (const SDL_Event* event) { return event->button.button; };
    }; //Button

    /**
     * @struct Trackball, Represents a joystick trackball.
     */
    struct Trackball {
        static int which (const SDL_Event* event) { return event->jball.ball; };
    }; //Trackball

    /**
     * @struct User, Represents a key.
     */
    struct User {
        static int which (const SDL_Event* event) { return event->user.code; };
    }; //User
}; //event
}; //sdl

#endif //SDL_EVENT_COMPONENTS_H

