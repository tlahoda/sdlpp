/**
 * @file Floor.h
 * Contains the Floor class.
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
#ifndef SDL_EXAMPLES_FLOOR_H
#define SDL_EXAMPLES_FLOOR_H

#include <GL/glu.h>

namespace sdl {
namespace examples {
    /**
     * @class Floor
     * @brief Represents a floor.
     */
    class Floor {
        public:
            /**
             * Constructs a Floor.
             *
             * @param xMin The minimum x..
             * @param xMax The maximum x..
             * @param zMin The minimum y.
             * @param zMax The maximum y.
             */
            Floor (float xMin, float xMax, float zMin, float zMax)
                : xMin_ (xMin), xMax_ (xMax),
                  zMin_ (zMin), zMax_ (zMax) {};

            /**
             * Renders the Floor.
             */
            virtual void render () const {
                glMatrixMode (GL_MODELVIEW);
                
                glColor3ub (0, 255, 0);
                for (float i = xMin_; i < xMax_; i += 0.1f) {
                    glBegin (GL_LINES);
                    glVertex3f (i, 0.0f, zMin_);
                    glVertex3f (i, 0.0f, zMax_);
                    glEnd ();
                }
                
                glColor3ub (0, 255, 0);
                for (float i = zMin_; i < zMax_; i += 0.1f) {
                    glBegin (GL_LINES);
                    glVertex3f (xMin_, 0.0f, i);
                    glVertex3f (xMax_, 0.0f, i);
                    glEnd ();
                }
            };

        private:
            /**
             * The minimum x.
             */
            float xMin_;

            /**
             * The maximum x.
             */
            float xMax_;

            /**
             * The minimum z.
             */
            float zMin_;

            /**
             * The maximum z.
             */
            float zMax_;
    }; //Floor
}; //examples
}; //sdl

#endif //SDL_EXAMPLES_FLOOR_H

