/**
 * @file Surface.h
 * Contains the Surface class.
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
#ifndef SDL_VIDEO_SURFACE_H
#define SDL_VIDEO_SURFACE_H

#include <string>
#include <stdexcept>

#include <boost/shared_ptr.hpp>

#include <SDL.h>

#include "sdlpp/misc/Rect.h"
#include "sdlpp/misc/Color.h"

namespace sdl {
namespace video {
    using namespace std;
    using namespace misc;

    /**
     * @class Surface
     * @brief Represents a surface.
     */
    class Surface {
        public:
            /**
             * Constructs a Surface from the current display surface.
             *
             * @throw runtime_error Throws a runtime_error if unable to get current system display.
             */
            Surface () : surface_ (SDL_GetVideoSurface (), &SDL_FreeSurface) {
                if (surface_ == NULL)
                    throw runtime_error (SDL_GetError ());
            };

            /**
             * Constructs a Surface from a SDL_Surface structure.
             *
             * @param The SDL_Surface structure.
             *
             * @throw runtime_error Throws a runtime_error if surface is NULL.
             */
            Surface (SDL_Surface* surface) : surface_ (surface, &SDL_FreeSurface) {
                if (surface_ == NULL)
                    throw runtime_error (SDL_GetError ());
            };

            /**
             * Constructs a Surface from a file.
             *
             * @param fileName The name of the file.
             *
             * @throw runtime_error Throws a runtime_error if unable to load bitmap.
             */
            Surface (const string& fileName) : surface_ (SDL_LoadBMP (fileName.c_str ()), &SDL_FreeSurface) {
                if (surface_ == NULL)
                    throw runtime_error (SDL_GetError ());
            };

            /**
             * Constructs a Surface.
             *
             * @param height The height.
             * @param width The width.
             * @param bpp The bits per pixel.
             * @param flags The surface flags.
             *
             * @throw runtime_error Throws a runtime_error if unable to set video mode.
             */
            Surface (int height, int width, int bpp, unsigned int flags)
              : surface_ (SDL_SetVideoMode (height, width, bpp, flags)) {
                if (surface_ == NULL)
                    throw runtime_error (SDL_GetError ());
            };

            /**
             * Constructs a Surface.
             *
             * @param flags The SDL Surface flags.
             * @param rect A rectangle with the height and width.
             * @param bpp The number of bits per pixel.
             * @param mask The color mask.
             *
             * @throw runtime_error Throws a runtime_error if unable to create RGB surface.
             */
            Surface (Uint32 flags, const Rect& rect, int bpp, const Color& mask)
              : surface_ (SDL_CreateRGBSurface (flags, rect.width (), rect.height (), bpp, 
                                                mask.red (), mask.green (), mask.blue (), mask.alpha ()), 
                                                &SDL_FreeSurface) {
                if (surface_ == NULL)
                    throw runtime_error (SDL_GetError ());
            };

            /**
             * Constructs a Surface from the provided pixel data.
             *
             * @param pixels The pixel data.
             * @param rect A rectangle with the height and width.
             * @param bpp The number of bits per pixel.
             * @param pitch The size of the scanline in bytes, width in pixels * bytes per pixel.
             * @param mask The color mask.
             *
             * @throw runtime_error Throws a runtime_error if unable to create RGB surface.
             */
            Surface (void *pixels, const Rect& rect, int bpp, int pitch, const Color& mask)
              : surface_ (SDL_CreateRGBSurfaceFrom (pixels, rect.width (), rect.height (), bpp, pitch, 
                                                    mask.red (), mask.green (), mask.blue (), mask.alpha ()), 
                                                    &SDL_FreeSurface) {
                if (surface_ == NULL)
                    throw runtime_error (SDL_GetError ());
            };

            /**
             * Destroys the Surface.
             */
            ~Surface () {};

            /**
             * Copy constructs a Surface.
             *
             * @param rhs The Surface to copy.
             */
            Surface (const Surface& rhs) : surface_ (rhs.surface_) {};
            
            /**
             * The assignment operator.
             *
             * @param rhs The Surface from which to assign.
             *
             * @return A reference to this Surface.
             */
            Surface& operator= (const Surface& rhs) {
                if (this != &rhs) 
                    surface_ = rhs.surface_;
                return *this;
            };

            /**
             * Blits the source rectangle from one Surface onto the destination rectangle of this Surface.
             *
             * @param surface The Surface from which to blit.
             * @param srcRect The source rectangle.
             * @param dstRect The destination rectangle.
             *
             * @return A reference to this Surface.
             *
             * @throw runtime_error Throws a runtime_error if unable to blit.
             */
            Surface& blit (Surface& surface, const Rect& srcRect, const Rect& dstRect) {
                SDL_Rect src;
                src.w = srcRect.width ();
                src.h = srcRect.height ();
                src.x = srcRect.x ();
                src.y = srcRect.y ();
                SDL_Rect dst;
                dst.w = dstRect.width ();
                dst.h = dstRect.height ();
                dst.x = dstRect.x ();
                dst.y = dstRect.y ();
                if (SDL_BlitSurface (surface.to_c (), &src, surface_.get (), &dst) == -1)
                    throw runtime_error (SDL_GetError ());
                return *this;
            };

            /**
             * Returns the height.
             * 
             * @return The height.
             */
            int height () { return surface_->h; };

            /**
             * Returns the width.
             *
             * @return The width.
             */
            int width () { return surface_->w; };

            /**
             * Returns the number of bits per pixel.
             *
             * @return The number of bits per pixel.
             */
            int bpp () { return surface_->format->BitsPerPixel; };

            /**
             * Locks the Surface.
             *
             * @return True if successful, false otherwise.
             */
            bool lock () { return SDL_LockSurface (surface_.get ()) == 0; };

            /**
             * Unlock the Surface.
             */
            void unlock () { SDL_UnlockSurface (surface_.get ()); };

            /**
             * Save the Surface to the named file.
             *
             * @param fileName The name of the file.
             *
             * @return True if successful, false otherwise.
             */
            bool save (const string& fileName) { return SDL_SaveBMP (surface_.get (), fileName.c_str ()) == 0; };
             
            /**
             * Exposes the underlying SDL_Surface structure.
             *
             * @return The SDL_Surface structure.
             */
            SDL_Surface* const to_c () const { return surface_.get (); };

        private:
            /**
             * The SDL_Surface structure.
             */
            boost::shared_ptr<SDL_Surface> surface_;
    }; //Surface
}; //video
}; //sdl

#endif //SDL_VIDEO_SURFACE_H

