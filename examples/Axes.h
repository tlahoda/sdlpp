/**
 * @file Axes.h, Contains the Axes class.
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
#ifndef SDL_EXAMPLES_AXES_H
#define SDL_EXAMPLES_AXES_H

#include <GL/glu.h>

namespace sdl {
namespace examples {
    /**
     * @class Aces, Represents axes.
     */
    class Axes {
        public:
            /**
             * Renders the Axes.
             *
             * @return void.
             */
            virtual void render () const {
                glMatrixMode (GL_MODELVIEW);

                //+X
                glBegin (GL_LINES);
                glColor3ub (255, 0, 0);
                glVertex3f (0.0f, 0.0f, 0.0f);
                glVertex3f (50.0f, 0.0f, 0.0f);
                glEnd ();

                //+Y
                glBegin (GL_LINES);
                glColor3ub (0, 255, 0);
                glVertex3f (0.0f, 0.0f, 0.0f);
                glVertex3f (0.0f, 50.0f, 0.0f);
                glEnd ();

                //+Z
                glBegin (GL_LINES);
                glColor3ub (0, 0, 255);
                glVertex3f (0.0f, 0.0f, 0.0f);
                glVertex3f (0.0f, 0.0f, 50.0f);
                glEnd ();
            };
    }; //Axes
}; //examples
}; //sdl

#endif //SDL_EXAMPLES_AXES_H

