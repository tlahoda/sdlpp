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
#include <stdexcept>

#include <SDL.h>

#include "sdlpp/subsystem/Subsystem.h"
#include "sdlpp/audio/Wav.h"

namespace sdl {
namespace audio {
    /*
     * @class Audio, Represents the audio system.
     */
    class Audio {
        public:
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
              : obtained_ () {
                SDL_AudioSpec desired;
                desired.freq = freq;
                desired.format = format;
                desired.channels = channels;
                //desired.silence = silence;
                desired.samples = samples;
                //desired.size = size;
                //desired.callback = mix;
                desired.userdata = 0;

                if (SDL_OpenAudio (&desired, &obtained_) == -1)
                    throw runtime_error ("Failed to open audio.");
                SDL_PauseAudio (0);
             };

            /**
             * Closes the audio system.
             */
            ~Audio () { SDL_CloseAudio (); };
            
            /**
             * Determines if the audio playback is playing.
             *
             * @return bool, True if playing, false otherwise.
             */
            bool isPlaying () { return SDL_GetAudioStatus () == SDL_AUDIO_PLAYING; };

            /**
             * Determines if the audio playback is paused.
             *
             * @return bool, True if paused, false otherwise.
             */
            bool isPaused () { return SDL_GetAudioStatus () == SDL_AUDIO_PAUSED; };

            /**
             * Determines if the audio playback is stopped.
             *
             * @return bool, True if stopped, false otherwise.
             */
            bool isStopped () { return SDL_GetAudioStatus () == SDL_AUDIO_STOPPED; };

            /**
             * Starts audio playback.
             *
             * @return bool, True is successful, false otherwise.
             */
            bool play () {
                SDL_PauseAudio (0);
                return isPlaying ();
            };

            /**
             * Plays a Wav.
             *
             * @param Wav& wav, The Wav to play.
             *
             * @return Audio&, A reference to this Audio.
             */
            Audio& play (Wav& wav) {
                /*SDL_LoadWAV (wav.name_.c_str (), obtained_, &wav.audioBuf_, &wav.audioLen_);
                SDL_AudioCVT cvt;
                SDL_BuildAudioCVT (&cvt, obtained_->format, obtained_->channels, obtained_->freq, AUDIO_S8, 1, 11000);
                cvt.buf = (Uint8*)malloc (wav.audioLen_ * cvt.len_mult);
                memcpy (cvt.buf, wav.audioBuf_, wav.audioLen_);
                cvt.len = wav.audioLen_;
                SDL_ConvertAudio (&cvt);
                SDL_FreeWAV (wav.audioBuf_);

                wav.audioBuf_ = cvt.buf;
                wav.audioLen_ = cvt.len_cvt;

                SDL_PauseAudio (0);*/
                return *this;
            };

            /**
             * Pauses Audio playback.
             *
             * @return bool, True is successful, false otherwise.
             */
            bool pause () {
                SDL_PauseAudio (1);
                return isPaused ();
            };

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
            SDL_AudioSpec obtained_;
    }; //Audio
}; //audio
}; //sdl

#endif //SDL_AUDIO_AUDIO_H

