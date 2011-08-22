/**
* @file Joystick.h, Contains the Joystick class.
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
#ifndef SDL_DEVICES_JOYSTICK_H
#define SDL_DEVICES_JOYSTICK_H

#include <string>
#include <stdexcept>

#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>

#include <SDL.h>

#include "sdlpp/subsystem/Joystick.h"
#include "sdlpp/devices/Axis.h"
#include "sdlpp/devices/JoystickButton.h"
#include "sdlpp/devices/Hat.h"
#include "sdlpp/devices/Trackball.h"

namespace sdl {
namespace devices {
  using namespace misc;

    /**
     * @class Joystick, Represents a joystick.
     */
    class Joystick {
        public:
            /**
             * Constructs a Joystick.
             *
             * @param int index, The index of the joystick.
             */
            Joystick (int index) : joystick_ (open (index)) {
                SDL_PumpEvents ();
                SDL_Event* joyEvents = new SDL_Event[18];
                SDL_PeepEvents (joyEvents, 18, SDL_GETEVENT, SDL_EVENTMASK (SDL_JOYAXISMOTION) | SDL_EVENTMASK (SDL_JOYBUTTONUP) | SDL_EVENTMASK (SDL_JOYBUTTONDOWN));
                delete[] joyEvents;
            };

            /**
             * Destroy a Joystick.
             */
            ~Joystick () { if (joystick_) SDL_JoystickClose (joystick_); };

            /**
             * Gets the implementation dependent name of the joystick.
             *
             * @return std::string, The joystick's name.
             */
            std::string name () { return SDL_JoystickName (SDL_JoystickIndex (joystick_)); };

            /**
             * Returns the index of the joystick.
             *
             * @return int, The index of the joystick.
             */
            int index () { return index_; };
            
            /**
             * Gets the number of joystick axes.
             *
             * return int, The number of joystick axes.
             */
            int numAxes () { return SDL_JoystickNumAxes (joystick_); };

            /**
             * Gets the number og joystick buttons.
             *
             * return int, The number of joystick buttons.
             */
            int numButtons () { return SDL_JoystickNumButtons (joystick_); };
            
            /**
             * Gets the number of joystick hats.
             *
             * return int, The number of joystick hats.
             */
            int numHats () { return SDL_JoystickNumHats (joystick_); };
            
            /**
             * Gets the number of joystick trackballs.
             *
             * return int, The number of joystick trackballs.
             */
            int numTrackballs () { return SDL_JoystickNumBalls (joystick_); };

            /**
             * Returns the state of the given joystick axis.
             *
             * @param Axis& axis, The axis for which to retrieve the state.
             *
             * @return Joystick&, A reference to this Joystick.
             */
            template<class Axis>
            Joystick& axisState (Axis& axis) {
                BOOST_STATIC_ASSERT ((boost::is_same<Axis, devices::Axis<Axis::value> >::value));
                axis.state = SDL_JoystickGetAxis (joystick_, Axis::value);
                return *this;
            };
            
            /**
             * Returns the state of the given joystick button.
             *
             * @param Button& button, The button for which to retrieve the state.
             *
             * @return Joystick&, A reference to this Joystick.
             */
            template<class Button>
            Joystick& buttonState (Button& button) {
                BOOST_STATIC_ASSERT ((boost::is_same<Button, devices::JoystickButton<Button::value> >::value));
                button.pressed = SDL_JoystickGetButton (joystick_, Button::value);
                return *this;
            };

            /**
             * Returns the state of the given joystick hat.
             *
             * @param Hat& hat, The hat for which to retrieve the state.
             *
             * @return Joystick&, A reference to this Joystick.
             */
            template<class Hat>
            Joystick& hatState (Hat& hat) {
                BOOST_STATIC_ASSERT ((boost::is_same<Hat, devices::Hat<Hat::value> >::value));
                hat.state = SDL_JoystickGetHat (joystick_, Hat::value);
                return *this;
            };

            /**
             * Returns the state of the given joystick trackball.
             *
             * @param Trackball& trackball, The trackball for which to retrieve the state.
             *
             * @return Joystick&, A reference to this Joystick.
             */
            template<class Trackball>
            Joystick& trackballState (Trackball& trackball) {
                BOOST_STATIC_ASSERT ((boost::is_same<Trackball, devices::Trackball<Trackball::value> >::value));
                SDL_JoystickGetBall (joystick_, Trackball::value, trackball.deltaX, trackball.deltaY);
                return *this;
            };

        private:
            /**
             * Copy constructs a Joystick.
             *
             * @param const Joystick& rhs, The Joystick to copy.
             */
            Joystick (const Joystick& rhs);

            /**
             * The assignment operator.
             *
             * @param const Joystick& rhs, The Joystick from which to assign.
             *
             * @return Joystick&, A reference to this Joystick.
             */
            Joystick& operator= (const Joystick& rhs);

            /**
             * Opens the Joystick.
             *
             * @param int index, The index of the joystick to open.
             *
             * @return SDL_Joystick*, The joystick's data structure.
             */
            SDL_Joystick* open (int index) {
                subsystem::Joystick::instance ();

                if (SDL_JoystickOpened (index)) throw std::runtime_error ("");

                SDL_Joystick* joystick = SDL_JoystickOpen (index);
                if (!joystick) throw std::bad_alloc ();
                return joystick;
            };

            /**
             * The joystick's data.
             */
            SDL_Joystick* joystick_;
    }; //Joystick
}; //devices
}; //sdl

#endif //SDL_DEVICES_JOYSTICK_H

