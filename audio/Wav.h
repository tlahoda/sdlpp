/**
 * /file Wav.h, Contains the Wav class.
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
#include <stexcpt>

#include <SDL.h>

namespace sdl {
namespace audio {
    /**
     * @class Wav, Represents a wav file.
     */
    class Wav {
        using namesapce std;
        public:
            /**
             * Opens the specified a wav file.
             *
             * @param const string& fileName, The name of the wav file.
             */
            Wav (const string& fileName)
              : name_ (fileName),
                audioBuf_ (0),
                audioLen_ (0),
                spec_ () {
                SDL_LoadWAV (name_.c_str (), &spec_, &audioBuf_, &audioLen_);
                if (spec_ == 0)
                    throw runtime_error ("");
            };

            /**
             * Copy constructs a wav file.
             *
             * @param const Wav& rhs, The wav file to copy.
             */
            Wav (const Wav& rhs)
              : name_ (rhs.name_),
                audioBuf_ (rhs.audioBuf_),
                audioLen_ (rhs.audioLen_),
                spec_ (rhs.spec_) {};

            /**
             * Destroys a wav file.
             */
            ~Wav () { SDL_FreeWAV (audioBuf_); };

            /**
             * The assignment operator.
             *
             * @param const Wav& rhs, The Wav from which to assign.
             *
             * @return Wav&, A reference to this Wav.
             */
            Wav& operator= (const Wav& rhs) { 
                if (this != &rhs) {
                    name_ = rhs.name_;
                    audioBuf_ = rhs.audioBuf_;
                    audioLen_ = rhs.audioLen_;
                    spec_ = rhs.spec_;
                }
                return *this; 
            };

        public:
            /**
             * The name of the wav file.
             */
            std::string name_;

            /**
             * The audio buffer.
             */
            char* audioBuf_;

            /**
             * The length of the audio buffer.
             */
            int audioLen_;

            /**
             * The SDL_AudioSpec structure.
             */
            SDL_AudioSpec spec_;
    }; //Wav
}; //audio
}; //sdl

#endif //SDL_AUDIO_WAV_H

