/**
 * @file CdRom.h, Contains the CdRom class.
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

#include <string>

#include <SDL.h>

namespace sdl {
namespace devices {
    /**
     * @struct CdRom, Represents a cd drive.
     */
    struct CdRom {
        /**
         * Opens the specified cd drive.
         *
         * @param int drive, The id of the cd drive.
         */
        CdRom (int drive) : cd_ (SDL_CD_Open (drive)) {};

        /**
         * Closes the cd drive.
         */
        ~CdRom () { SDL_CDClose (cd_); };

        /**
         * Returns a system dependent human readable name of the cd drive.
         *
         * @return string, The system dependent human readable name of the cd drive.
         */
        string name () { return SDL_CDName (cd_.id); };

        /**
         * Returns the status of the cd drive.
         *
         * @return CDstatus, The CDstatus.
         */
        CDstatus status () { return SDL_CDStatus (cd_); };

        /**
         * Determines if a cd is in the drive.
         *
         * @return bool, True if cd detected, false otherwise.
         */
        bool cdInDrive () { return CD_INDRIVE (status ()); };

        /**
         * Plays a cd starting a start frame for length number of frames.
         *
         * @param int start, The frame at which to start playing.
         * @param int length, The number of frames to play.
         *
         * @return bool, True if successful, false otherwise.
         */
        bool play (int start, int length) { return cdInDrive () ? SDL_CDPlay (cd_, start, length) == 0 : false; };

        /**
         * Plays tracks on the cd.
         *
         * @param int startTrack, The track to start playing.
         * @param int startFrame, The frame offset from the start of startTrack to begin playing.
         * @param int numTracks, The number of tracks to play.
         * @param int numFrames, The number of frames from the beginning of the last track to play.
         *
         * @return bool, True if successful, false otherwise.
         */
        bool playTracks (int startTrack, int startFrame, int numTracks, int numFrames) { return cdInDrive () ? SDL_CDPlayTracks (cd_, startTrack, startFrame, numTracks, numFrames) == 0 : false; };

        /**
         * Pauses a cd playing.
         *
         * @return bool, True if successful, false otherwise.
         */
        bool pause () { return SDL_CDPause (cd_) == 0; };

        /**
         * Resumes a cd playing.
         *
         * @return bool, True if successful, false otherwise.
         */
        bool resume () { return SDL_CDResume (cd_) == 0; };

        /**
         * Stop a cd from playing.
         *
         * @return bool, True if successful, false otherwise.
         */
        bool stop () { return SDL_CDStop (cd_) == 0; };

        /**
         * Ejects the cd.
         *
         * @return bool, Ture if successful, false otherwise.
         */
        bool eject () { return SDL_CDEject (cd_) == 0; };

        /**
         * Gets the underlying SDL_CD structure.
         *
         * @return SDL_CD*, The SDL_CD structure.
         */
        SDL_CD* get () { return cd_; } const;

        /**
         * Gets the underlying SDL_CD structure.
         *
         * @return SDL_CD*, The SDL_CD structure.
         */
        SDL_CD* get () { return cd_; };

        private:
            /**
             * The SDL_CD structure.
             */
            SDL_CD* cd_;
    }; //CdRom
}; //devices
}; //sdl

#endif //SDL_DEVICES_CDROM_H

