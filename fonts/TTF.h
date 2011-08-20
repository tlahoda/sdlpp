/**
 * @file TTF.h, Contains the TTF class.
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
#ifndef SDL_SUBSYSTEM_TTF_H
#define SDL_SUBSYSTEM_TTF_H

#include <stdexcept>

#include <SDL_ttf.h>

namespace sdl {
namespace subsystem {
    using namespace std;

    /**
     * @struct TTF, The True Type Font subsystem
     */
    struct TTF {
        /**
         * Returns an instance of the TTF subsystem.
         *
         * @return TTF&, A reference to the TTF subsystem.
         */
        static TTF& instance () {
            static TTF instance_;
            return instance_;
        };

        /**
         * Determines if the TTF subsystem is open.
         *
         * @return bool, True if the TTF subsystem is open, false otherwise.
         */
        static bool isOpen () {
            return TTF_WasInit ();
        };

        protected:
            /**
             * Opens the TTF subsystem.
             *
             * @return TTF&, A reference the this TTF subsystem.
             */
            TTF& open () {
                init ();
                return *this;
            };

            /**
             * Closes the TTF subssytem.
             *
             * @return TTF&, A reference the this TTF subsystem.
             */
            TTF& close () {
                quit ();
                return *this;
            };
           
        private:
            /**
             * Initialize the TTF subsystem.
             *
             * @return void.
             */
            void init () {
                if (!TTF_WasInit ())
                    if (TTF_Init () < 0) 
                        throw runtime_error (TTF_GetError ());
            };

            /**
             * Quits the TTF subssytem.
             *
             * @return void.
             */
            void quit () {
                if (TTF_WasInit ())
                    TTF_Quit ();
            };
        
            /**
             * Initializes the TTF subsystem.
             */
            TTF () { init (); };

            /**
             * Destroys the TTF subsystem.
             */
            ~TTF () { quit (); };
    }; //TTF
}; //subsystem
}; //sdl

#endif //SDL_SUBSYSTEM_TTF_H

