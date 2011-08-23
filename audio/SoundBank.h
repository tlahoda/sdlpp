/**
 * /file SoundBank.h, Contains the SoundBank class.
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
#ifndef SDL_AUDIO_SOUNDBANK_H
#define SDL_AUDIO_SOUNDBANK_H

#include <vector>

#include "sdlpp/audio/Wav.h"

namespace sdl {
namespace audio {
    using namespace std;

    /**
     * @class SoundBank, Represents a sound bank.
     */
    class SoundBank {
        public:
            /**
             * Returns the instance of the SoundBank.
             *
             * @return SoundBank&, A reference to this SoundBank.
             */
            static SoundBank& instance () {
                static SoundBank instance_;
                return instance_;
            };

            /**
             * Adds a Wav to the SoundBank.
             *
             * @return SoundBank&, A reference to this SoundBank.
             */
            SoundBank& add (const Wav& wav) {
                sounds_.push_back (wav);
                return *this;
            };

            /**
             * Returns the Wavs in the SoundBank.
             *
             * @return vector<Wav>&, The Wavs in the SoundBank.
             */
            vector<Wav>& sounds () { return sounds_; };

            /**
             * Clears a SoundBank.
             *
             * @return SoundBank&, A reference to this SoundBank.
             */
            SoundBank& clear () {
                sounds_.clear ();
                return *this;
            };

            /**
             * Cleans a SoundBank.
             *
             * @return SoundBank&, A reference to this SoundBank.
             */
            SoundBank& clean () { return *this; };

        private:
            /**
             * Constructs a SoundBank.
             */
            SoundBank ()
              : sounds_ () {};

            /**
             * Destroys a SoundBank.
             */
            ~SoundBank () {};
            
            /**
             * Copy constructs a SoundBank.
             *
             * @param const SoundBank& rhs, The SoundBank to copy.
             */
            SoundBank (const SoundBank& rhs);

            /**
             * The assignment operator
             *
             * @param const SoundBank& rhs, The SoundBank from which to assign.
             *
             * @return SoundBank&, A reference to this SoundBank.
             */
            SoundBank& operator= (const SoundBank& rhs);

            /**
             * The Wavs in the sound bank.
             */
            vector<Wav> sounds_;
    }; //SoundBank
}; //audio
}; //sdl

#endif //SDL_AUDIO_SOUNDBANK_H

