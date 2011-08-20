/**
 * @file JoystickEvents.h, Contains the joystick event classes.
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
#ifndef SDL_EVENT_JOYSTICKEVENTS_H
#define SDL_EVENT_JOYSTICKEVENTS_H

#include <boost/static_assert.hpp>

#include <SDL.h>

#include "sdlpp/devices/Axis.h"
#include "sdlpp/devices/Trackball.h"
#include "sdlpp/devices/Hat.h"
#include "sdlpp/devices/JoystickButton.h"
#include "sdlpp/event/MultiComparator.h"
#include "sdlpp/event/Event.h"
#include "sdlpp/misc/is_base_of_all.h"

namespace sdl {
namespace event {
    using namespace devices;
    using namespace misc;

    /**
     * @struct JoystickAxisBase, Base for joystick axis events that exposes the SDL_JoyAxisEvent structure.
     */
    struct JoystickAxisBase : public EventBase {
        /**
         * Constructs a JoystickAxisBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit JoystickAxisBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_JoyAxisEvent structure.
         *
         * @return const SDL_JoyAxisEvent&, The SDL_JoyAxisEvent structure.
         */
        const SDL_JoyAxisEvent& get () const { return event_->jaxis; };
    
        /**
         * Exposes the SDL_JoyAxisEvent structure.
         *
         * @return const SDL_JoyAxisEvent&, The SDL_JoyAxisEvent structure.
         */
        const SDL_JoyAxisEvent& get () { return event_->jaxis; };
    }; //JoystickAxisBase

    /**
     * @struct JoystickAxisMotion, Represents a joystick axis motion event.
     *
     * @tparam Axes, The axes that compse this joystick axis motion event.
     */
    template<int... Axes>
    struct JoystickAxisMotion : public Event<MultiComparator<Axis, SDL_JOYAXISMOTION, Axes...>, JoystickAxisBase> {
        /**
         * Constructs a JoystickAxisMotion from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit JoystickAxisMotion (const SDL_Event* event) : Event<MultiComparator<Axis, SDL_JOYAXISMOTION, Axes...>, JoystickAxisBase> (event) {};
    }; //JoystickAxisMotion

    /**
     * @struct JoystickTrackballBase, Base for joystick trackball events that exposes the SDL_JoyBallEvent structure.
     */
    struct JoystickTrackballBase : public EventBase {
        /**
         * Constructs a JoystickTrackballBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit JoystickTrackballBase (const SDL_Event* event) : EventBase (event) {};
        
        /**
         * Exposes the SDL_JoyBallEvent structure.
         *
         * @return const SDL_JoyBallEvent&, The SDL_JoyBallEvent structure.
         */
        const SDL_JoyBallEvent& get () const { return event_->jball; };

        /**
         * Exposes the SDL_JoyBallEvent structure.
         *
         * @return const SDL_JoyBallEvent&, The SDL_JoyBallEvent structure.
         */
        const SDL_JoyBallEvent& get () { return event_->jball; };
    }; //JoystickTrackballBase

    /**
     * @struct JoystickTrackballMotion, Represents a joystick trackball motion event.
     */
    template<int... Balls>
    struct JoystickTrackballMotion : public Event<MultiComparator<Trackball, SDL_JOYBALLMOTION, Balls...>, JoystickTrackballBase> {
        /**
         * Constructs a JoystickTrackballMotion from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit JoystickTrackballMotion (const SDL_Event* event) : Event<MultiComparator<Trackball, SDL_JOYBALLMOTION, Balls...>, JoystickTrackballBase> (event) {};
    }; //JoystickTrackballMotion

    /**
     * @struct JoystickHatBase, Base for joystick hat events that exposes the SDL_JoyHatEvent structure.
     */
    struct JoystickHatBase : public EventBase {
        /**
         * Constructs a JoystickHatBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit JoystickHatBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_JoyHatEvent structure.
         *
         * @return const SDL_JoyHatEvent&, The SDL_JoyHatEvent structure.
         */
        const SDL_JoyHatEvent& get () const { return event_->jhat; };

        /**
         * Exposes the SDL_JoyHatEvent structure.
         *
         * @return const SDL_JoyHatEvent&, The SDL_JoyHatEvent structure.
         */
        const SDL_JoyHatEvent& get () { return event_->jhat; };
    }; //JoystickHatBase

    /**
     * @struct JoystickHatMotion, Represents a joystick hat motion event.
     *
     * @tparam Hats, The hats that compose this joystick hat motion event.
     */
    template<int... Hats>
    struct JoystickHatMotion : public Event<MultiComparator<Hat, SDL_JOYHATMOTION, Hats...>, JoystickHatBase> {
        /**
         * Constructs a JoystickHatMotion from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit JoystickHatMotion (const SDL_Event* event) : Event<MultiComparator<Hat, SDL_JOYHATMOTION, Hats...>, JoystickHatBase> (event) {};
    }; //JoystickHatMotion

    /**
     * @struct JoystickButtonBase, Base for joystick button events that exposes the SDL_JoyButtonEvent structure.
     */
    struct JoystickButtonBase : public EventBase {
        /**
         * Constructs a JoystickButtonBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        JoystickButtonBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_JoyButtonEvent structure.
         *
         * @return const SDL_JoyButtonEvent&, The SDL_JoyButtonEvent structure.
         */
        const SDL_JoyButtonEvent& get () const { return event_->jbutton; };

        /**
         * Exposes the SDL_JoyButtonEvent structure.
         *
         * @return const SDL_JoyButtonEvent&, The SDL_JoyButtonEvent structure.
         */
        const SDL_JoyButtonEvent& get () { return event_->jbutton; };
    }; //JoystickButtonBase

    /**
     * @struct JoystickButtonPress, Represents a joystick button press event.
     *
     * @tparam Buttons, The Buttons that compose this joystick button press event.
     */
    template<int... Buttons>
    struct JoystickButtonPress : public Event<MultiComparator<JoystickButton, SDL_JOYBUTTONDOWN, Buttons...>, JoystickButtonBase> {
        /**
         * Constructs a JoystickButtonPress from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit JoystickButtonPress (const SDL_Event* event = 0) : Event<MultiComparator<JoystickButton, SDL_JOYBUTTONDOWN, Buttons...>, JoystickButtonBase> (event) {};
    }; //JoystickButtonPress

    /**
     * @struct JoystickButtonRelease, Represents a joystick button release event.
     *
     * @tparam Buttons, The Buttons that compose this joystick button release event.
     */
    template<int... Buttons>
    struct JoystickButtonRelease : public Event<MultiComparator<JoystickButton, SDL_JOYBUTTONUP, Buttons...>, JoystickButtonBase> {
        /**
         * Constructs a JoystickButtonRelease from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        explicit JoystickButtonRelease (const SDL_Event* event = 0) : Event<MultiComparator<JoystickButton, SDL_JOYBUTTONUP, Buttons...>, JoystickButtonBase> (event) {};
    }; //JoystickButtonRelease
}; //event
}; //sdl

#endif //SDL_EVENT_JOYSTICKEVENTS_H

