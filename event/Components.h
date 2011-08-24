/**
 * @file Components.h
 * Contains the Axis, Hat, JoystickButton, Key, Mousebutton, Trackball, and User classes.
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
     * @struct Axis
     * @brief Represents a joystick axis.
     */
    struct Axis {
        /**
         * Returns an int that identifies the component from which the event came.
         *
         * @param event The event from which to get the identity.
         *
         * @return The component identity.
         */
        static int which (const SDL_Event* event) { return event->jaxis.axis; };
    };//Axis

    /**
     * @struct Hat
     * @brief Represents a joystick hat.
     */
    struct Hat {
        /**
         * Returns an int that identifies the component from which the event came.
         *
         * @param event The event from which to get the identity.
         *
         * @return The component identity.
         */
        static int which (const SDL_Event* event) { return event->jhat.hat; };
    }; //Hat
    
    /**
     * @struct JoystickButton
     * @brief Represents a joystick button.
     */
    struct JoystickButton {
        /**
         * Returns an int that identifies the component from which the event came.
         *
         * @param event The event from which to get the identity.
         *
         * @return The component identity.
         */
        static int which (const SDL_Event* event) { return event->jbutton.button; };
    }; //Button

    /**
     * @struct Key
     * @brief Represents a key.
     */
    struct Key {
        /**
         * Returns an int that identifies the component from which the event came.
         *
         * @param event The event from which to get the identity.
         *
         * @return The component identity.
         */
        static int which (const SDL_Event* event) { return event->key.keysym.sym; };
    }; //Key

    /**
     * @struct MouseButton
     * @brief Represents a mouse button.
     */
    struct MouseButton {
        /**
         * Returns an int that identifies the component from which the event came.
         *
         * @param event The event from which to get the identity.
         *
         * @return The component identity.
         */
        static int which (const SDL_Event* event) { return event->button.button; };
    }; //Button

    /**
     * @struct Trackball
     * @brief Represents a joystick trackball.
     */
    struct Trackball {
        /**
         * Returns an int that identifies the component from which the event came.
         *
         * @param event The event from which to get the identity.
         *
         * @return The component identity.
         */
        static int which (const SDL_Event* event) { return event->jball.ball; };
    }; //Trackball

    /**
     * @struct User
     * @brief Represents a key.
     */
    struct User {
        /**
         * Returns an int that identifies the component from which the event came.
         *
         * @param event The event from which to get the identity.
         *
         * @return The component identity.
         */
        static int which (const SDL_Event* event) { return event->user.code; };
    }; //User
}; //event
}; //sdl

#endif //SDL_EVENT_COMPONENTS_H

