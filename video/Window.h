/**
 * @file Window.h
 * Contains the Window class.
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
#ifndef SDL_VIDEO_WINDOW_H
#define SDL_VIDEO_WINDOW_H

#include <stdexcept>
#include <string>

#include <SDL.h>
//Error being caused by #include <SDL_syswm.h>
//#include <SDL_syswm.h>

#include "sdlpp/Sdl.h"
#include "sdlpp/video/Surface.h"
#include "sdlpp/video/Icon.h"

namespace sdl {
namespace video {
    using namespace std;
 
    /**
     * @class Window
     * @brief Represents an SDL window.
     */
    class Window {
        public:
            /**
             * Constructs a Window with a caption and an icon.
             */
            Window (const string& caption, const Icon& icon)
              : caption_ (caption), icon_ (icon) {};

            /**
             * Destroys the Window.
             */
            ~Window () {};

            /**
             * Returns the Window's caption.
             *
             * @return The Window's caption.
             */
            string caption () { return caption_; };
            
            /**
             * Sets the Window's caption.
             *
             * @param caption The Window's new caption.
             *
             * @return A reference to this Window.
             */
            Window& caption (const string& caption) {
                caption_ = caption;
                SDL_WM_SetCaption (caption.c_str (), icon_.name ().c_str ());
                return *this;
            };

            /**
             * Returns the window's icon.
             *
             * @return The Window's icon.
             */
            Icon& icon () { return icon_; };
            
            /**
             * Sets the Window's icon.
             *
             * @param icon The Window's new icon.
             *
             * @return A reference to this Window.
             */
            Window& icon (const Icon& icon) {
                icon_ = icon;
                SDL_WM_SetCaption (caption_.c_str (), icon_.name ().c_str ());
                return *this;
            };
            
            /**
             * Attempts to minimize the window.
             *
             * @return True if successful, false otherwise.
             */
            bool minimize () { return SDL_WM_IconifyWindow () != 0; };

            /**
             * Grabs the mouse and keyboard input.
             *
             * @return True if successful, false otherwise.
             */
            bool grabInput () { return SDL_WM_GrabInput (SDL_GRAB_ON) == SDL_GRAB_ON; };

            /**
             * Releases the mouse and keyboard.
             *
             * @return True if successful, false otherwise.
             */
            bool releaseInput () { return SDL_WM_GrabInput (SDL_GRAB_OFF) == SDL_GRAB_OFF; };

            /**
             * Determines if the input if grabbed.
             *
             * @return True if grabbed, false otherwise.
             */
            bool inputGrabbed () { return SDL_WM_GrabInput (SDL_GRAB_QUERY) == SDL_GRAB_ON; };

            /**
             * Toggles fullscreen mode.
             *
             * @param surface The Surface for which to toggle fullscreen mode.
             *
             * @return True if successful, false otherwise.
             */
            bool fullScreen (const Surface& surface) { return SDL_WM_ToggleFullScreen (surface.to_c ()) == 1; };

            //Error being caused by #include <SDL_syswm.h>
            /**
             * Gets the window manager specific information.
             *
             * @return The information.
             *
             * @throw runtime_error Throws a runtime_error if unimplemented or failed.
             */
            /*SDL_SysWMinfo info () {
                SDL_SysWMinfo i;
                i.version = Sdl::instance ().compileVersion ();
                int res = SDL_GetWMInfo (&i);
                if (res == 0)
                    throw runtime_error ("unimplemented");
                else if (res == -1)
                    throw runtime_error ("failed");
                return i;
            };*/

        private:
            /**
             * Copy constructs a Window.
             *
             * @param rhs The Window to copy.
             */
            Window (const Window& rhs);

            /**
             * The assignment operator.
             *
             * @param rhs The Window from which to assign.
             *
             * @return A reference to this Window.
             */
            Window& operator= (const Window& rhs);

        private:
            /**
             * The Window's caption.
             */
            string caption_;

            /**
             * The Window's Icon.
             */
            Icon icon_;
    }; //Window
}; //video
}; //sdl

#endif //SDL_VIDEO_WINDOW_H

