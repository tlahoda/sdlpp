/**
 * @file Subsystem.h, Contains the subsystem classes.
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
#ifndef SDL_SUBSYSTEM_SUBSYSTEM_H
#define SDL_SUBSYSTEM_SUBSYSTEM_H

#include <stdexcept>
#include <string>
#include <iostream>

#include <SDL.h>

#include "sdlpp/Sdl.h"

namespace sdl {
namespace subsystem {
    /**
     * @struct Subsystem, Represents a SDL subsystem.
     *
     * @tparam T, The SDL subsystem type.
     * @tparam Base, The Subsystem base class.
     */
    template<int T, class Base>
    class Subsystem : public Base {
        public:
            /**
             * Returns a reference to the Subsystem instance.
             *
             * @return Subsystem&, A reference to the Subsystem.
             */
            static Subsystem& instance () {
                static Subsystem instance_;
                return instance_;
            };

            /**
             * Determines if the Subsystem is open.
             *
             * @return bool, True if the subsystem is open, false otherwise.
             */
            static bool isOpen () { return SDL_WasInit (T) == T; };
           
            /**
             * Opens the Subsystem.
             *
             * @return Subsystem&, A reference to this Subsystem.
             */
            Subsystem& open () {
                init ();
                return *this;
            };

            /**
             * Closes the Subsystem.
             *
             * @return Subsystem&, A reference to this Subsystem.
             */
            Subsystem& close () {
                quit ();
                return *this;
            };
 
        protected:
            /**
             * Initializes the Subsystem.
             *
             * @return Subsystem&, A reference to this Subsystem.
             */
            Subsystem& init () {
                if (!isOpen ()) {
                    Sdl::instance ();
                    SDL_InitSubSystem (T);
                    if (!isOpen ()) throw std::runtime_error (Base::name () + " subsystem failed to initialize.");
                }
                return *this;
            };

            /**
             * Quits the Subsystem.
             *
             * @return Subsystem&, A reference to this Subsystem.
             */
            Subsystem& quit () {
                if (isOpen ()) SDL_QuitSubSystem (T);
                return *this;
            };

            /**
             * Constructs a Subsystem.
             */
            Subsystem () : Base () { init (); };

            /**
             * Copy constructs a Subsystem.
             *
             * @param const Subsystem& rhs, The Subsystem to copy.
             */
            Subsystem (const Subsystem& rhs) {};

            /**
             * Destroys the Subsystem.
             */
            ~Subsystem () { quit (); };

            /**
             * The assignment operator.
             *
             * @param const Subsystem& rhs, The Subsystem from which to assign.
             *
             * @return Subsystem&, A reference to this Subsystem.
             */
            Subsystem& operator= (const Subsystem& rhs) {};
    }; //Subsystem

    /**
     * Base for the audio subsystem.
     */
    struct AudioBase {
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return const std::string, The name of the Subsystem.
             */
            static const std::string name () { return "Audio"; };
    }; //AudioBase

    /**
     * @typedef Subsystem<SDL_INIT_AUDIO, AudioBase> Audio,
     *          Represents the audio subsystem.
     */
    typedef Subsystem<SDL_INIT_AUDIO, AudioBase> Audio;

    /**
     * @struct CdRomBase, Base for the cd-rom subsystem.
     */
    struct CdRomBase {
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return const std::string, The name of the Subsystem.
             */
            static const std::string name () { return "Cd-Rom"; };
    }; //CdRomBase

    /**
     * @typedef Subsystem<SDL_INIT_CDROM, CdRomBase> CdRom,
     *          Represents the cd-rom subsystem.
     */
    typedef Subsystem<SDL_INIT_CDROM, CdRomBase> CdRom;

    /**
     * @struct EverythingBase, Base to the everything subsystem.
     */
    struct EverythingBase {
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return const std::string, The name of the Subsystem.
             */
            static const std::string name () { return "Everything"; };
    }; //EverythingBase

    /**
     * @typedef Subsystem<SDL_INIT_EVERYTHING, EverythingBase> Everything,
     *          Represents the everything subsystem.
     */
    typedef Subsystem<SDL_INIT_EVERYTHING, EverythingBase> Everything;

    /**
     * @struct EventThreadBase, Base for the event thread subsystem.
     */
    struct EventThreadBase {
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return const std::string, The name of the Subsystem.
             */
            static const std::string name () { return "EventThread"; };
    }; //EventThreadBase

    /**
     * @typedef Subsystem<SDL_INIT_EVENTTHREAD, EventThreadBase> EventThread,
     *          Represents the event thread subsystem.
     */
    typedef Subsystem<SDL_INIT_EVENTTHREAD, EventThreadBase> EventThread;

    /**
     * @struct JoystickBase, Base for the joystick subsystem.
     */
    struct JoystickBase {
        /**
         * Updates the state of all joysticks.
         */
        void update () { SDL_JoystickUpdate (); };

        /**
         * Returns the number of available joysticks.
         */
        int numJoysticks () { return SDL_NumJoysticks (); };

        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return const std::string, The name of the Subsystem.
             */
            static const std::string name () { return "Joystick"; };
    }; //JoystickBase

    /**
     * @typedef Subsystem<SDL_INIT_JOYSTICK, JoystickBase> Joystick,
     *          Represents the joystick subsystem.
     */
    typedef Subsystem<SDL_INIT_JOYSTICK, JoystickBase> Joystick;

    /**
     * @struct NoParachuteBase, Base for the no parachute subsystem.
     */
    struct NoParachuteBase {
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return const std::string, The name of the Subsystem.
             */
            static const std::string name () { return "NoParachute"; };
    }; //NoParachuteBase

    /**
     * @typedef Subsystem<SDL_INIT_NOPARACHUTE, NoParachuteBase> NoParachute,
     *          Represents the no parachute subsystem.
     */
    typedef Subsystem<SDL_INIT_NOPARACHUTE, NoParachuteBase> NoParachute;

    /**
     * @struct TimerBase, Base for the timer subsystem.
     */
    struct TimerBase {
        /**
         * Returns the number of milliseconds since SDL library initialization.
         */
        unsigned int ticks () { return SDL_GetTicks (); };

        /**
         * Waits the specified number of milliseconds.
         *
         * @param unsigned int interval, The number of milliseconds to wait.
         */
        TimerBase& delay (unsigned int interval) {
            SDL_Delay (interval);
            return *this;
        };
        
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return const std::string, The name of the Subsystem.
             */
            static const std::string name () { return "Timer"; };
    }; //TimerBase

    /**
     * @typedef Subsystem<SDL_INIT_TIMER, TimerBase> Timer,
     *          Represents the timer subsystem.
     */
    typedef Subsystem<SDL_INIT_TIMER, TimerBase> Timer;

    /**
     * @struct VideoBase, Base for the video subsystem.
     */
    struct VideoBase {
        /**
         * Constructs a VideoBase.
         */
        VideoBase () {};

        void swapBuffers () { SDL_GL_SwapBuffers (); };

        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return const std::string, The name of the Subsystem.
             */
            static const std::string name () { return "Video"; };
    }; //VideoBase

    /**
     * @typedef Subsystem<SDL_INIT_VIDEO, VideoBase> Video,
     *          Represents the video subsystem.
     */
    typedef Subsystem<SDL_INIT_VIDEO, VideoBase> Video;
}; //subsystem
}; //sdl

#endif //SDL_SUBSYSTEM_SUBSYSTEM_H

