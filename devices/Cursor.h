/**
 * @file Cursor.h, Contains the Cursor class.
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
#ifndef SDL_DEVICES_CURSOR_H
#define SDL_DEVICES_CURSOR_H

#include <SDL.h>

#include "sdlpp/misc/Rect.h"
#include "sdlpp/misc/Coordinate.h"

namespace sdl {
namespace devices {
    using namespace misc;

    /**
     * class Cursor, Represents the system pointer.
     */
    class Cursor {
        public:
            /**
             * Constructs a Cursor.
             *
             * @param Uint8 *data, The color of each Cursor pixel.
             * @param Uint8 *mask, The mask for each Cursor pixel.
             * @param const Rect& rect, A rectangle containing the height and width of the Cursor.
             * @param const Coordinate& pos, The position of the upper-left corner of the Cursor.
             *
             */
            Cursor (Uint8 *data, Uint8 *mask, const Rect& rect, const Coordinate& pos)
                : cursor_ (SDL_CreateCursor (data, mask, 
                                             rect.width (), rect.height (),
                                             pos.x (), pos.y ())) {
            };

            /**
             * Destroys a Cursor.
             */
            ~Cursor () { 
                SDL_FreeCursor (cursor_); 
            };

            /**
             * Moves the Cursor to the specified position. 
             *
             * @param const Coordinate& pos, The position to which to move the upper-left corner of the Cursor.
             *
             * @return void.
             */
            void move (const Coordinate& pos) {
                SDL_Warp (pos.x (), pos.y ());
            };

        private:
            Cursor (const Cursor& rhs);
            Cursor& operator= (const Cursor& rhs);

            /*
             * The system pointer.
             */
            SDL_Cursor* cursor_;
    }; //Cursor
}; //devices
}; //sdl

#endif //SDL_DEVICES_CURSOR_H

