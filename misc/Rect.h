/**
 * @file Rect.h, Contains the Rect class.
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
#ifndef SDL_MISC_RECT_H
#define SDL_MISC_RECT_H

#include <boost/mpl/aux_/config/static_constant.hpp>

#include <SDL.h>

namespace sdl {
namespace misc {
    /**
     * @class Rect, Represents a rectangle.
     */
    class Rect {
        public:
            /**
             * Constructs a Rect.
             *
             * @param unsigned int height, The height.
             * @param unsigned int width, The width.
             * @param short x, The x offset.
             * @param short y, The y offset.
             */
            Rect (unsigned int height, unsigned int width, short x, short y) : rect_ () {
                rect_.w = width;
                rect_.h = height;
                rect_.x = x;
                rect_.y = y;
            };

            /**
             * Returns the underlying SDL_Rect*.
             *
             * @return SDL_Rect*, The SDL_Rect structure.
             */
            SDL_Rect* operator* () { return &rect_; };

            /**
             * Returns the height.
             *
             * @return int, The height.
             */
            int height () const { return rect_.h; };
            
            /**
             * Returns the width.
             *
             * @return int, The width.
             */
            int width () const { return rect_.w; };
            
            /**
             * Return the x offset.
             *
             * @return int, The x offset.
             */
            int x () const { return rect_.x; };

            /**
             * Returns the y offset.
             *
             * @return int, The y offset.
             */
            int y () const { return rect_.y; };

        private:
            /**
             * The rectangle structure.
             */
            SDL_Rect rect_;
    }; //Rect
}; //misc
}; //sdl

#endif //SDL_MISC_RECT_H

