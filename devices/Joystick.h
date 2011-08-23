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
#include <utility>

#include <SDL.h>

#include "sdlpp/subsystem/Subsystem.h"
#include "sdlpp/event/Components.h"

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
            ~Joystick () { SDL_JoystickClose (joystick_); };

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
            int index () { return SDL_JoystickIndex (joystick_); };
            
            /**
             * Gets the number of joystick axes.
             *
             * return int, The number of joystick axes.
             */
            int numAxes () { return SDL_JoystickNumAxes (joystick_); };

            /**
             * Gets the number of joystick buttons.
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
             * Returns the position of the given joystick axis.
             *
             * @param int axis, The axis.
             *
             * @return short, The position.
             */
            short axisPosition (int axis) { return SDL_JoystickGetAxis (joystick_, axis); };
            
            /**
             * Determines if the button is pressed.
             *
             * @param int button, The button.
             *
             * @return bool, True if the button is pressed, false otherwise.
             */
            bool isPressed (int button) { return SDL_JoystickGetButton (joystick_, button) == 1; };

            /**
             * Returns the state of the given joystick hat.
             *
             * @param int hat, The hat.
             *
             * @return char, The state.
             */
            char hatState (int hat) { return SDL_JoystickGetHat (joystick_, hat); };

            /**
             * Returns the relative motion of the given joystick trackball.
             *
             * @param int trackball, The trackball.
             *
             * @return pair<int, int>, The relative motion.
             *
             * @throw runtime_error, Throws a runtime_error if unable to determine trackball motion.
             */
            pair<int, int> trackballMotion (int trackball) {
                pair<int, int> res = make_pair (0, 0);
                if (SDL_JoystickGetBall (joystick_, trackball, &res.first, &res.second) == -1)
                    throw runtime_error ("Unable to determine trackball motion");
                return res;
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
             *
             * @throw runtime_error, Throws a runtime_error if index is invalid or unable to open joystick.
             */
            SDL_Joystick* open (int index) {
                if (index > subsystem::Joystick::instance ().numJoysticks () - 1)
                    throw runtime_error ("Invalid joystick index.");

                SDL_Joystick* joystick = SDL_JoystickOpen (index);
                if (joystick == NULL) 
                    throw runtime_error ("Failed to open joystick.");
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

