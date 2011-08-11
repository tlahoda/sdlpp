/**
 * @file Coordinate.h, Contains the Coordinate class.
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
#ifndef SDL_MISC_COORDINATE_h
#define SDL_MISC_COORDINATE_h

namespace sdl {
namespace misc {
    /**
     * @struct Coordinate, Represents a 2 dimensional coordinate.
     */
    struct Coordinate {
        /**
         * Constructs a Coordinate from a x and a y.
         *
         * @param int x, The x coordinate.
         * @param int y, The y coordinate.
         */
        Coordinate (int x, int y) : x_ (x), y_ (y) {};

        /**
         * Returns the x coordinate.
         *
         * @return int, The x coordinate.
         */
        int x () const { return x_; };

        /**
         * Returns the y coordinate.
         *
         * @return int, The y coordinate.
         */
        int y () const { return y_; };

        private:
            /**
             * The x coordinate.
             */
            int x_;

            /**
             * The y coordinate.
             */
            int y_;
    }; //Coordinate
}; //misc
}; //sdl

#endif //SDL_MISC_COORDINATE_h

