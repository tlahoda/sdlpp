/**
 * @file Overlay.h, Contains the Overlay class.
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
#ifndef SDL_VIDEO_OVERLAY_H
#define SDL_VIDEO_OVERLAY_H

#include <SDL.h>

#include "sdlpp/misc/Rect.h"
#include "sdlpp/video/Surface.h"

/*typedef struct{
  Uint32 format;          //Overlay format
  int w, h;               //Width and height of overlay
  int planes;             //Number of planes in the overlay. Usually either 1 or 3
  Uint16 *pitches;        //An array of pitches, one for each plane. Pitch is the length of a row in bytes.
  Uint8 **pixels;         //An array of pointers to the data of each plane. The overlay should be locked before these pointers are used.
  Uint32 hw_overlay:1;    //This will be set to 1 if the overlay is hardware accelerated.
} SDL_Overlay;*/

namespace sdl {
namespace video {
    using namespace misc;

    /**
     * @class Overlay, .
     */
    class Overlay {
        public:
            /**
             * Constructs an Overlay.
             *
             * @param const Rect& rect, A rectangle describing the height and width of the Overlay.
             * @param Uint32 format, The format of the Overlay.
             * @param const surface& display, The Surface on which to display the Overlay.
             */
            Overlay (const Rect& rect, Uint32 format, const Surface& display)
              : overlay_ (SDL_CreateYUVOverlay (rect.width (), rect.height (), format, display.to_c ())) {
            };

            /**
             * Destroys the Overlay.
             */
            ~Overlay () {
                SDL_FreeYUVOverlay (overlay_);
            };

            /**
             * Locks the Overlay.
             *
             * @return bool, True if the Overlay was locked, false otherwise.
             */
            bool lock () {
                return (SDL_LockYUVOverlay (overlay_) == 0);
            };
            
            /**
             * Unlocks the Overlay.
             *
             * @return void.
             */
            void unlock () {
                SDL_UnlockYUVOverlay (overlay_);
            };

            /**
             * Displays the Overlay.
             *
             * @return bool, True if successful, false otherwise.
             */
            bool display () {
                return (SDL_DisplayYUVOverlay (overlay_, SDL_Rect *dstrect) == 0);
            };

        private:
            /**
             * Copy constructs and Overlay.
             *
             * @param const Overlat& rhs, The Overlay to copy.
             */
            Overlay (const Overlay& rhs);

            /**
             * The assignment operator.
             *
             * @param const Overlay& rhs, The Overlay from which to assign.
             *
             * @return Overlay&, A reference to this Overlay.
             */
            Overlay& operator= (const Overlay& rhs);

        private:
            /**
             * The SDL_Overlay structure.
             */
            SDL_Overlay* overlay_;
    }; //Overlay
}; //video
}; //sdl

#endif //SDL_VIDEO_OVERLAY_H

