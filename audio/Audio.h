/**
 * /file Audio.h, Contains the Audio class.
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
#ifndef SDL_AUDIO_AUDIO_H
#define SDL_AUDIO_AUDIO_H

#include <string>
#include <iostream>

#include <SDL.h>

#include "sdlpp/subsystem/Subsystem.h"
#include "sdlpp/audio/Wav.h"
#include "sdlpp/audio/SoundBank.h"

namespace sdl {
namespace audio {
    /*
     * @class Audio, Represents the audio system.
     */
    class Audio {
        private:
            /**
             * Opens the audio system.
             *
             * @param int freq, The audio frequenct in samples per second.
             * @param unsigned short format, The audio data format.
             * @param unsigned char channels, The number of audio channels.
             * @param unsigned char silence, The audio buffer silence value.
             * @param unsigned short samples, The audio buffer size in samples.
             * @param unsigned int size, The audio buffer size in bytes.
             *
             * @return SDL_AudioSpec*, The obtained SDL_AudioSpec.
             */
            SDL_AudioSpec* open (int freq, unsigned short format, unsigned char channels, unsigned char silence, unsigned short samples, unsigned int size) {
                SDL_AudioSpec* desired = new SDL_AudioSpec ();
                desired->freq = freq;
                desired->format = format;
                desired->channels = channels;
                //desired->silence = silence;
                desired->samples = samples;
                //desired->size = size;
                //desired->callback = mix;
                desired->userdata = 0;

                SDL_AudioSpec* obtained = new SDL_AudioSpec ();
                if (SDL_OpenAudio (desired, obtained) < 0) {
                    delete desired;
                    delete obtained;
                    //throw BadSubSystemInit ("Unable to open audio.");
                }
                SDL_PauseAudio (0);
                delete desired;
                return obtained;
            };

        public:
            /**
             * Constructs the default audio system.
             */
            Audio () : obtained_ (0) {};

            /**
             * Opens the audio system.
             *
             * @param int freq, The audio frequenct in samples per second.
             * @param unsigned short format, The audio data format.
             * @param unsigned char channels, The number of audio channels.
             * @param unsigned char silence, The audio buffer silence value.
             * @param unsigned short samples, The audio buffer size in samples.
             * @param unsigned int size, The audio buffer size in bytes.
             */
            Audio (int freq, unsigned short format, unsigned char channels, unsigned char silence, unsigned short samples, unsigned int size)
             : obtained_ (open (freq, format, channels, silence, samples, size)) {};

            /**
             * Closes the audio system.
             */
            ~Audio () {
                SDL_CloseAudio ();
                delete obtained_;
            };

            /**
             * Starts audio playback.
             *
             * @return Audio&, A reference to this Audio.
             */
            Audio& play () {
                SDL_PauseAudio (0);
                return *this;
            };

            /**
             * Plays a Wav.
             *
             * @param Wav& wav, The Wav to play.
             *
             * @return Audio&, A reference to this Audio.
             */
            Audio& play (Wav& wav) {
                /*SoundBank& sb = SoundBank::instance ();

                SDL_LoadWAV (wav.name_.c_str (), obtained_, &wav.audioBuf_, &wav.audioLen_);
                SDL_AudioCVT cvt;
                SDL_BuildAudioCVT (&cvt, obtained_->format, obtained_->channels, obtained_->freq, AUDIO_S8, 1, 11000);
                cvt.buf = (Uint8*)malloc (wav.audioLen_ * cvt.len_mult);
                memcpy (cvt.buf, wav.audioBuf_, wav.audioLen_);
                cvt.len = wav.audioLen_;
                SDL_ConvertAudio (&cvt);
                SDL_FreeWAV (wav.audioBuf_);

                wav.audioBuf_ = cvt.buf;
                wav.audioLen_ = cvt.len_cvt;

                lock ();
                sb.add (wav);
                unlock ();

                SDL_PauseAudio (0);*/
                return *this;
            };

            /**
             * Pauses Audio playback.
             *
             * @return Audio&, A reference to this Audio.
             */
            Audio& pause () {
                SDL_PauseAudio (1);
                return *this;
            };
            
            /**
             * Gets the Audio status.
             *
             * @return int, The status.
             */
            int status () { return SDL_GetAudioStatus (); };

            /**
             * Locks an Audio.
             *
             * @return Audio&, A reference to this Audio.
             */
            Audio& lock () {
                SDL_LockAudio ();
                return *this;
            };
            
            /**
             * Unlocks an Audio.
             *
             * @return Audio&, A reference to this Audio.
             */
            Audio& unlock () {
                SDL_UnlockAudio ();
                return *this;
            };

        private:
            /**
             * Copy constructs an Audio.
             *
             * @param const Audio& rhs, The Audio to copy.
             */
            Audio (const Audio& rhs);
            
            /**
             * The assignment operator
             *
             * @param const Audio& rhs, The Audio from which to assign.
             *
             * @return Audio&, A reference to this Audio.
             */
            Audio& operator= (const Audio& rhs);

        private:
            /*
             * The SDL_AudioSpec structure.
             */
            SDL_AudioSpec* obtained_;
    }; //Audio
}; //audio
}; //sdl

#endif //SDL_AUDIO_AUDIO_H

