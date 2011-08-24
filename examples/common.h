/**
 * @file common.h
 * Contains common functions and values.
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
#ifndef SDL_EXAMPLES_COMMON_H
#define SDL_EXAMPLES_COMMON_H

#include <boost/numeric/ublas/vector.hpp>

namespace sdl {
namespace examples {
    /**
     * typedef boost::numeric::ublas::vector<float> Vector
     * @brief The type of a numeric vector.
     */
    typedef boost::numeric::ublas::vector<float> Vector;

    /**
     * Makes a Vector.
     *
     * @param x The x element.
     * @param y The y element.
     * @param z The z element..
     *
     * @return The vector.
     */
    static inline Vector make_Vector (float x, float y, float z) {
        Vector vec (3);
        vec[0] = x;
        vec[1] = y;
        vec[2] = z;
        return vec;
    };
    
    /**
     * Degrees to radians conversion factor.
     */
    static const float DEG2RAD = 180.0f / 3.141596f;

    /**
     * The width of the screen.
     */
    static const int SCREEN_WIDTH = 1024;

    /**
     * The height of the screen.
     */
    static const int SCREEN_HEIGHT = 1024;

    /**
     * The color depth of the screen.
     */
    static const int COLOR_DEPTH = 32;

    /**
     * The frame delay.
     */
    static const unsigned int FRAME_DELAY = 33;
}; //examples
}; //sdl

#endif //SDL_EXAMPLES_COMMON_H

