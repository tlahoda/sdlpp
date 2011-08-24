/**
 * @file Wav.h
 * Contains the Wav class.
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
#ifndef SDL_AUDIO_WAV_H
#define SDL_AUDIO_WAV_H

#include <string>
#include <stdexcept>

#include <SDL.h>

namespace sdl {
namespace audio {
    using namespace std;

    /**
     * @class Wav
     * @brief Represents a wav file.
     */
    class Wav {
        public:
            /**
             * Opens the specified a wav file.
             *
             * @param fileName The name of the wav file.
             *
             * @throw runtime_error Throws a runtime_error if the wav could not be loaded.
             */
            Wav (const string& fileName)
              : name_ (fileName),
                audioBuf_ (0),
                audioLen_ (0),
                spec_ () {
                if (SDL_LoadWAV (name_.c_str (), &spec_, &audioBuf_, &audioLen_) == NULL)
                    throw runtime_error (SDL_GetError ());
            };

            /**
             * Destroys a wav file.
             */
            ~Wav () { SDL_FreeWAV (audioBuf_); };

            /**
             * The name of the wav file.
             */
            std::string name_;

            /**
             * The audio buffer.
             */
            unsigned char* audioBuf_;

            /**
             * The length of the audio buffer.
             */
            unsigned int audioLen_;

            /**
             * The SDL_AudioSpec structure.
             */
            SDL_AudioSpec spec_;

        private:
            /**
             * Copy constructs a wav file.
             *
             * @param rhs The wav file to copy.
             */
            Wav (const Wav& rhs);

            /**
             * The assignment operator.
             *
             * @param rhs The Wav from which to assign.
             *
             * @return A reference to this Wav.
             */
            Wav& operator= (const Wav& rhs);
    }; //Wav
}; //audio
}; //sdl

#endif //SDL_AUDIO_WAV_H

