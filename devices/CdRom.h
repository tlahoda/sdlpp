/**
 * @file CdRom.h
 * Contains the CdRom class.
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
#ifndef SDL_DEVICES_CDROM_H
#define SDL_DEVICES_CDROM_H

#include <stdexcept>
#include <string>

#include <SDL.h>

#include "sdlpp/subsystem/Subsystem.h"

namespace sdl {
namespace devices {
    /**
     * @struct CdRom
     * @brief Represents a cd drive.
     */
    struct CdRom {
        /**
         * Opens the specified cd drive.
         *
         * @param drive The id of the cd drive.
         */
        CdRom (int drive) : cd_ (open (drive)) {};

        /**
         * Closes the cd drive.
         */
        ~CdRom () { SDL_CDClose (cd_); };

        /**
         * Returns a system dependent human readable name of the cd drive.
         *
         * @return The system dependent human readable name of the cd drive.
         */
        string name () { return SDL_CDName (cd_->id); };

        /**
         * Returns the status of the cd drive.
         *
         * @return The CDstatus.
         */
        CDstatus status () { return SDL_CDStatus (cd_); };

        /**
         * Determines if a cd is in the drive.
         *
         * @return True if cd detected, false otherwise.
         */
        bool cdInDrive () { return CD_INDRIVE (status ()); };

        /**
         * Plays a cd starting a start frame for length number of frames.
         *
         * @param start The frame at which to start playing.
         * @param length The number of frames to play.
         *
         * @return True if successful, false otherwise.
         */
        bool play (int start, int length) { return cdInDrive () ? SDL_CDPlay (cd_, start, length) == 0 : false; };

        /**
         * Plays tracks on the cd.
         *
         * @param startTrack The track to start playing.
         * @param startFrame The frame offset from the start of startTrack to begin playing.
         * @param numTracks The number of tracks to play.
         * @param numFrames The number of frames from the beginning of the last track to play.
         *
         * @return True if successful, false otherwise.
         */
        bool playTracks (int startTrack, int startFrame, int numTracks, int numFrames) { return cdInDrive () ? SDL_CDPlayTracks (cd_, startTrack, startFrame, numTracks, numFrames) == 0 : false; };

        /**
         * Pauses a cd playing.
         *
         * @return True if successful, false otherwise.
         */
        bool pause () { return SDL_CDPause (cd_) == 0; };

        /**
         * Resumes a cd playing.
         *
         * @return True if successful, false otherwise.
         */
        bool resume () { return SDL_CDResume (cd_) == 0; };

        /**
         * Stop a cd from playing.
         *
         * @return True if successful, false otherwise.
         */
        bool stop () { return SDL_CDStop (cd_) == 0; };

        /**
         * Ejects the cd.
         *
         * @return Ture if successful, false otherwise.
         */
        bool eject () { return SDL_CDEject (cd_) == 0; };

        /**
         * Gets the underlying SDL_CD structure.
         *
         * @return The SDL_CD structure.
         */
        SDL_CD* get () const { return cd_; };

        /**
         * Gets the underlying SDL_CD structure.
         *
         * @return The SDL_CD structure.
         */
        SDL_CD* get () { return cd_; };

        private:
            /**
             * Opens the specified cd drive.
             *
             * @param drive,The id of the cd drive.
             *
             * @return The SDL_CD structure.
             *
             * @throw runtime_error Throws a runtime_error if index is invalid or if it failed to open the cd drive.
             */
            SDL_CD* open (int drive) {
                if (drive > subsystem::CdRom::instance ().numDrives () - 1)
                    throw runtime_error ("Invalid drive id.");

                SDL_CD* cd = SDL_CDOpen (drive);
                if (cd == NULL)
                    throw runtime_error ("Failed to open cd drive.");
                return cd;
            };

            /**
             * The SDL_CD structure.
             */
            SDL_CD* cd_;
    }; //CdRom
}; //devices
}; //sdl

#endif //SDL_DEVICES_CDROM_H

