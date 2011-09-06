/**
 * @file example.cpp, Contains main function.
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
#include <string>

#include <GL/glu.h>

#include "sdlpp/Sdl.h"
#include "sdlpp/subsystem/Subsystem.h"
#include "sdlpp/video/Surface.h"
#include "sdlpp/event/EventLoop.h"
#include "sdlpp/examples/common.h"
#include "sdlpp/examples/ExampleHandler.h"
#include "sdlpp/examples/Axes.h"
#include "sdlpp/examples/Floor.h"

/**
 * The main function.
 *
 * @param int argc, The number of arguments.
 * @param char** argv, The arguments.
 *
 * @return int, The exit status.
 */
int main (int argc, char** argv) {
    using namespace sdl;
    using namespace sdl::subsystem;
    using namespace sdl::misc;
    using namespace sdl::event;
    using namespace sdl::video;
    using namespace sdl::examples;

    Sdl::instance ();
    Video& video = Video::instance ();
    
    Surface screen (SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_DEPTH, SDL_HWSURFACE | SDL_OPENGL);

    glEnable (GL_DEPTH_TEST);

    bool running = true;
    Vector location = make_Vector (0.0f, 1.5f, 10.0f);
    float xRot = 0.0f;
    float yRot = 0.0f;

    ViewerHandler handler (running, location, xRot, yRot);
    Dispatcher dispatcher (handler);

    Axes axes;
    Floor floor (-50.0f, 50.0f, -50.0f, 50.0f);

    glMatrixMode (GL_PROJECTION);
    gluPerspective (50.0f, 1.0f, 1.0f, 1000.0f);

    while (running) {
        glMatrixMode (GL_MODELVIEW);
        glLoadIdentity ();

        glRotatef (xRot, 1.0f, 0.0f, 0.0f);
        glRotatef (yRot, 0.0f, 1.0f, 0.0f);
        glTranslatef (-location[0], -location[1], -location[2]);

        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        axes.render ();
        floor.render ();

        EventLoop::run (dispatcher, FRAME_DELAY);

        video.swapBuffers ();
    }
    return 0;
}; //main

