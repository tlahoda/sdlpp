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

#include <stdexcept>

#include <SDL.h>

#include "sdlpp/misc/Rect.h"
#include "sdlpp/misc/Coordinate.h"

namespace sdl {
namespace devices {
    using namespace std;
    using namespace misc;

    /**
     * class Cursor, Represents the system pointer.
     */
    class Cursor {
        public:
            Cursor () : cursor_ (SDL_GetCursor ()) {
                if (cursor_ == NULL)
                    throw runtime_error ("Unable to get system cursor.");
            };

            /**
             * Constructs a Cursor.
             *
             * @param Uint8 *data, The color of each Cursor pixel.
             * @param Uint8 *mask, The mask for each Cursor pixel.
             * @param const Rect& rect, A rectangle containing the height and width of the Cursor.
             * @param const Coordinate<int>& pos, The position of the upper-left corner of the Cursor.
             */
            Cursor (Uint8 *data, Uint8 *mask, const Rect& rect, const Coordinate<int>& pos)
                : cursor_ (SDL_CreateCursor (data, mask, 
                                             rect.width (), rect.height (),
                                             pos.x (), pos.y ())) {
                if (cursor_ == NULL)
                    throw runtime_error ("Failed to create the Cursor.");
            };

            /**
             * Destroys a Cursor.
             */
            ~Cursor () { SDL_FreeCursor (cursor_); };

            /**
             * Moves the Cursor to the specified position. 
             *
             * @param const Coordinate<short>& pos, The position to which to move the upper-left corner of the Cursor.
             *
             * @return void.
             */
            void move (const Coordinate<short>& pos) { SDL_WarpMouse (pos.x (), pos.y ()); };

            /**
             * Shows the Cursor.
             *
             * @return bool, True if successful, false otherwise.
             */
            bool show () { return SDL_ShowCursor (SDL_ENABLE) == SDL_ENABLE; };

            /**
             * Hides the Cursor.
             *
             * @return bool, True if successful, false otherwise.
             */
            bool hide () { return SDL_ShowCursor (SDL_DISABLE) == SDL_DISABLE; };

            /**
             * Determines if the Cursor if visible or not.
             *
             * @return bool, True is Cursor is visible, false otherwise.
             */
            bool isVisible () { return SDL_ShowCursor (SDL_QUERY) == SDL_ENABLE; };

            /**
             * Toggles the visibility of the Cursor.
             *
             * @return bool, True if successful, false otherwise.
             */
            bool toggle () {
                return isVisible () ? SDL_ShowCursor (SDL_DISABLE) == SDL_DISABLE : SDL_ShowCursor (SDL_ENABLE) == SDL_ENABLE;
            };

            /**
             * Activates the Cursor.
             *
             * @return void.
             */
            void activate () { SDL_SetCursor (cursor_); };

            /**
             * Force the cursor to redraw.
             *
             * @return void.
             */
            void redraw () { SDL_SetCursor (NULL); }; 

        private:
            /**
             * Copy constructs a Cursor.
             *
             * @param const Cursor& rhs, The Cursor to copy.
             */
            Cursor (const Cursor& rhs);

            /**
             * The assignment operator.
             *
             * @param const Cursor& rhs, The Cursor from which to assign.
             *
             * @return Cursor&, A reference to this Cursor.
             */
            Cursor& operator= (const Cursor& rhs);

            /*
             * The system pointer.
             */
            SDL_Cursor* cursor_;
    }; //Cursor
}; //devices
}; //sdl

#endif //SDL_DEVICES_CURSOR_H

