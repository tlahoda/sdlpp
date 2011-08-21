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
     *
     * @tparam T, The type of the coordinate elements.
     */
    template<typename T>
    struct Coordinate {
        /**
         * Constructs a Coordinate from a x and a y.
         *
         * @param T x, The x coordinate.
         * @param T y, The y coordinate.
         */
        Coordinate (T x, T y) : x_ (x), y_ (y) {};

        /**
         * Returns the x coordinate.
         *
         * @return T, The x coordinate.
         */
        T x () const { return x_; };

        /**
         * Returns the y coordinate.
         *
         * @return T, The y coordinate.
         */
        T y () const { return y_; };

        private:
            /**
             * The x coordinate.
             */
            T x_;

            /**
             * The y coordinate.
             */
            T y_;
    }; //Coordinate
}; //misc
}; //sdl

#endif //SDL_MISC_COORDINATE_h

