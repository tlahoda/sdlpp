/**
 * /file Sdl.h, Contains the Sdl class.
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
#ifndef SDL_SDL_H
#define SDL_SDL_H

#include <stdexcept>

#include <SDL.h>

namespace sdl {
    using namespace std;

    /**
     * Represents the SDL system.
     */
    class Sdl {
        public:
            /**
             * Returns an instance of the SDL system.
             *
             * @return Sdl&, A reference to the Sdl instance.
             */
            static Sdl& instance () {
                static Sdl instance_;
                return instance_;
            };

            /**
             * Returns the compile-time version of the SDL library.
             *
             * @return SDL_version, The SDL_version structure.
             */
            SDL_version compileVersion () {
                SDL_version version;
                SDL_VERSION (&version);
                return version;
            };

            /**
             * Returns the runtime version of the SDL library.
             *
             * @return const SDL_version*, The SDL_version structure.
             */
            const SDL_version* linkedVersion () {
                return SDL_Linked_Version ();
            };

        private:
            /**
             * Initializes the SDL system.
             */
            Sdl () {
                if (SDL_Init (0) == -1) 
                    throw std::runtime_error (SDL_GetError ());
            };

            /**
             * Copy constructs the Sdl.
             *
             * @param const Sdl& rhs, The Sdl to copy.
             */
            Sdl (const Sdl& rhs);
            
            /**
             * Destroys the SDL system.
             */
            ~Sdl () {
                SDL_Quit ();
            };
            
            /**
             *
             *
             * @param const Sdl& rhs, The Sdl from which to assign.
             *
             * @return Sdl&, A reference to thsi Sdl.
             */
            Sdl& operator= (const Sdl& rhs);
    }; //Sdl
}; //sdl

#endif //SDL_SDL_H

