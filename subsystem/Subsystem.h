/**
 * @file Subsystem.h
 * Contains the subsystem classes.
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

#include <SDL.h>

#include "sdlpp/Sdl.h"

namespace sdl {
namespace subsystem {
    using namespace std;

    /**
     * @struct Subsystem
     * @brief Represents a SDL subsystem.
     *
     * @tparam T The SDL subsystem type.
     * @tparam Base The Subsystem base class.
     */
    template<int T, class Base>
    class Subsystem : public Base {
        public:
            /**
             * Returns a reference to the Subsystem instance.
             *
             * @return A reference to the Subsystem.
             */
            static Subsystem& instance () {
                static Subsystem instance_;
                return instance_;
            };

            /**
             * Determines if the Subsystem is open.
             *
             * @return True if the subsystem is open, false otherwise.
             */
            static bool isOpen () { return SDL_WasInit (T) == T; };
           
            /**
             * Opens the Subsystem.
             *
             * @return A reference to this Subsystem.
             */
            Subsystem& open () {
                init ();
                return *this;
            };

            /**
             * Closes the Subsystem.
             *
             * @return A reference to this Subsystem.
             */
            Subsystem& close () {
                quit ();
                return *this;
            };
 
        protected:
            /**
             * Initializes the Subsystem.
             *
             * @return A reference to this Subsystem.
             *
             * @throw runtime_error Throws a runtime_error if unable to initialize subsystem.
             */
            Subsystem& init () {
                if (SDL_InitSubSystem (T) == -1)
                    throw runtime_error (Base::name () + " subsystem failed to initialize.");
                return *this;
            };

            /**
             * Quits the Subsystem.
             *
             * @return A reference to this Subsystem.
             */
            Subsystem& quit () {
                SDL_QuitSubSystem (T);
                return *this;
            };

            /**
             * Constructs a Subsystem.
             */
            Subsystem () : Base () { init (); };

            /**
             * Copy constructs a Subsystem.
             *
             * @param rhs The Subsystem to copy.
             */
            Subsystem (const Subsystem& rhs) {};

            /**
             * Destroys the Subsystem.
             */
            ~Subsystem () { quit (); };

            /**
             * The assignment operator.
             *
             * @param rhs The Subsystem from which to assign.
             *
             * @return A reference to this Subsystem.
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
             * @return The name of the Subsystem.
             */
            static const string name () { return "Audio"; };
    }; //AudioBase

    /**
     * @typedef Subsystem<SDL_INIT_AUDIO, AudioBase> Audio
     * @brief Represents the audio subsystem.
     */
    typedef Subsystem<SDL_INIT_AUDIO, AudioBase> Audio;

    /**
     * @struct CdRomBase
     * @brief Base for the cd-rom subsystem.
     */
    struct CdRomBase {
        /**
         * The number of cd drives attached to the system.
         *
         * @return The number of cd drives.
         */
        int numDrives () { return SDL_CDNumDrives (); };

        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return The name of the Subsystem.
             */
            static const string name () { return "Cd-Rom"; };
    }; //CdRomBase

    /**
     * @typedef Subsystem<SDL_INIT_CDROM, CdRomBase> CdRom,
     * @brief Represents the cd-rom subsystem.
     */
    typedef Subsystem<SDL_INIT_CDROM, CdRomBase> CdRom;

    /**
     * @struct EverythingBase
     * @brief Base to the everything subsystem.
     */
    struct EverythingBase {
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return The name of the Subsystem.
             */
            static const string name () { return "Everything"; };
    }; //EverythingBase

    /**
     * @typedef Subsystem<SDL_INIT_EVERYTHING, EverythingBase> Everything,
     * @brief Represents the everything subsystem.
     */
    typedef Subsystem<SDL_INIT_EVERYTHING, EverythingBase> Everything;

    /**
     * @struct EventThreadBase
     * @brief Base for the event thread subsystem.
     */
    struct EventThreadBase {
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return The name of the Subsystem.
             */
            static const string name () { return "EventThread"; };
    }; //EventThreadBase

    /**
     * @typedef Subsystem<SDL_INIT_EVENTTHREAD, EventThreadBase> EventThread,
     * @brief Represents the event thread subsystem.
     */
    typedef Subsystem<SDL_INIT_EVENTTHREAD, EventThreadBase> EventThread;

    /**
     * @struct JoystickBase
     * @brief Base for the joystick subsystem.
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

        /**
         * Enables joystick event polling.
         * Warning: Calling this function may delete all events currently in the queue.
         *
         * @return True if successful, false otherwise.
         */
        bool enableEvents () { return SDL_JoystickEventState (SDL_ENABLE) == SDL_ENABLE; };

        /**
         * Disables joystick event polling.
         * Warning: Calling this function may delete all events currently in the queue.
         *
         * @return True if successful, false otherwise.
         */
        bool disableEvents () { return SDL_JoystickEventState (SDL_IGNORE) == SDL_IGNORE; };

        /**
         * Determines if joystick event polling is enabled.
         * Warning: Calling this function may delete all events currently in the queue.
         *
         * @return True if enabled, false otherwise.
         */
        bool areEventsEnabled () { return SDL_JoystickEventState (SDL_QUERY) == SDL_ENABLE; };

        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return The name of the Subsystem.
             */
            static const string name () { return "Joystick"; };
    }; //JoystickBase

    /**
     * @typedef Subsystem<SDL_INIT_JOYSTICK, JoystickBase> Joystick,
     * @brief Represents the joystick subsystem.
     */
    typedef Subsystem<SDL_INIT_JOYSTICK, JoystickBase> Joystick;

    /**
     * @struct NoParachuteBase
     * @brief Base for the no parachute subsystem.
     */
    struct NoParachuteBase {
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return The name of the Subsystem.
             */
            static const string name () { return "NoParachute"; };
    }; //NoParachuteBase

    /**
     * @typedef Subsystem<SDL_INIT_NOPARACHUTE, NoParachuteBase> NoParachute,
     * @brief Represents the no parachute subsystem.
     */
    typedef Subsystem<SDL_INIT_NOPARACHUTE, NoParachuteBase> NoParachute;

    /**
     * @struct TimerBase
     * @brief Base for the timer subsystem.
     */
    struct TimerBase {
        /**
         * Returns the number of milliseconds since SDL library initialization.
         */
        unsigned int ticks () { return SDL_GetTicks (); };

        /**
         * Waits the specified number of milliseconds.
         *
         * @param The number of milliseconds to wait.
         */
        TimerBase& delay (unsigned int interval) {
            SDL_Delay (interval);
            return *this;
        };
        
        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return The name of the Subsystem.
             */
            static const string name () { return "Timer"; };
    }; //TimerBase

    /**
     * @typedef Subsystem<SDL_INIT_TIMER, TimerBase> Timer,
     * @brief Represents the timer subsystem.
     */
    typedef Subsystem<SDL_INIT_TIMER, TimerBase> Timer;

    /**
     * @struct VideoBase, Base for the video subsystem.
     */
    struct VideoBase {
        /**
         * Swaps the OpenGL frame buffers if double-buffering is supported.
         */
        void swapBuffers () { SDL_GL_SwapBuffers (); };

        protected:
            /**
             * Returns the name of the Subsystem.
             *
             * @return The name of the Subsystem.
             */
            static const string name () { return "Video"; };
    }; //VideoBase

    /**
     * @typedef Subsystem<SDL_INIT_VIDEO, VideoBase> Video,
     * @brief Represents the video subsystem.
     */
    typedef Subsystem<SDL_INIT_VIDEO, VideoBase> Video;
}; //subsystem
}; //sdl

#endif //SDL_SUBSYSTEM_SUBSYSTEM_H

