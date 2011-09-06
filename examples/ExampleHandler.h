/**
 * @file ExampleHandler.h
 * Contains the ExampleHandler class.
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
#ifndef SDL_EXAMPLES_EXAMPLEHANDLER_H
#define SDL_EXAMPLES_EXAMPLEHANDLER_H

#include <algorithm>

#include <boost/mpl/vector.hpp>

#include "sdlpp/devices/Keyboard.h"
#include "sdlpp/event/KeyboardEvents.h"
#include "sdlpp/event/MouseEvents.h"
#include "sdlpp/examples/common.h"

namespace sdl {
namespace examples {
    using namespace std;
    using namespace sdl::devices;
    using namespace sdl::event;

    /**
     * @class ExampleHandler
     * @brief Handles events for the example.
     */
    class ExampleHandler {
        public:
            /**
             * The events handled by the handler.
             */
            typedef boost::mpl::vector<KeyPress<SDLK_ESCAPE, SDLK_q>,
                                       KeyPress<SDLK_a>,
                                       KeyPress<SDLK_d>,
                                       KeyPress<SDLK_w>,
                                       KeyPress<SDLK_s>,
                                       KeyPress<SDLK_r>,
                                       MouseButtonPress<SDL_BUTTON_LEFT>,
                                       MouseButtonRelease<SDL_BUTTON_LEFT>,
                                       MouseMotion> Events; 

            /**
             * Constructs an ExampleHandler.
             *
             * @param running Indicates whether or not to keep the program running.
             * @param location The viewing location.
             * @param xRot The rotation angle around the x axis.
             * @param yRot The rotation angle around the y axis.
             */
            ExampleHandler (bool& running, Vector& location, float& xRot, float& yRot)
              : running_ (running),
                location_ (location),
                xRot_ (xRot),
                yRot_ (yRot),
                mouseLook_ (false) {
                Keyboard::enableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
            }; 

        public:
            /**
             * Handles escape and q key press events.
             *
             * @param event The event.
             */
            void handle (const KeyPress<SDLK_ESCAPE, SDLK_q>& event) {
                running_ = false;
            };

            /**
             * Handles a key press events.
             *
             * @param event The event.
             */
            void handle (const KeyPress<SDLK_a>& event) {
                float yRotRad = yRot_ / DEG2RAD;

                Vector temp = make_Vector (location_[0] - cos (yRotRad) * 0.2f,
                                           location_[1],
                                           location_[2] - sin (yRotRad) * 0.2f);

                location_[0] = min (max (temp[0], -50.0f), 50.0f);
                location_[2] = min (max (temp[2], -50.0f), 50.0f);
            };

            /**
             * Handles d key press events.
             *
             * @param event The event.
             */
            void handle (const KeyPress<SDLK_d>& event) {
                float yRotRad = yRot_ / DEG2RAD;

                Vector temp = make_Vector (location_[0] + cos (yRotRad) * 0.2f,
                                           location_[1],
                                           location_[2] + sin (yRotRad) * 0.2f);

                location_[0] = min (max (temp[0], -50.0f), 50.0f);
                location_[2] = min (max (temp[2], -50.0f), 50.0f);
            };

            /**
             * Handles w key press events.
             *
             * @param event The event.
             */
            void handle (const KeyPress<SDLK_w>& event) {
                float yRotRad = yRot_ / DEG2RAD;
                float xRotRad = xRot_ / DEG2RAD; 

                Vector temp = make_Vector (location_[0] + sin (yRotRad),
                                           location_[1] - sin (xRotRad),
                                           location_[2] - cos (yRotRad));

                location_[0] = min (max (temp[0], -50.0f), 50.0f);
                location_[1] = min (max (temp[1], 1.5f), 50.0f);
                location_[2] = min (max (temp[2], -50.0f), 50.0f);
            };

            /**
             * Handles s key press events.
             *
             * @param event The event.
             */
            void handle (const KeyPress<SDLK_s>& event) {
                float yRotRad = yRot_ / DEG2RAD;
                float xRotRad = xRot_ / DEG2RAD;

                Vector temp = make_Vector (location_[0] - sin (yRotRad),
                                           location_[1] + sin (xRotRad),
                                           location_[2] + cos (yRotRad));

                location_[0] = min (max (temp[0], -50.0f), 50.0f);
                location_[1] = min (max (temp[1], 1.5f), 50.0f);
                location_[2] = min (max (temp[2], -50.0f), 50.0f);
            };

            /**
             * Handles r key press events.
             *
             * @param event The event.
             */
            void handle (const KeyPress<SDLK_r>& event) {
                location_[0] = 0.0f;
                location_[1] = 1.5f;
                location_[2] = 10.0f;

                xRot_ = 0.0f;
                yRot_ = 0.0f;
            };

            /**
             * Handles left mouse button press events. Starts mouse looking
             *
             * @param event The event.
             */
            void handle (const MouseButtonPress<SDL_BUTTON_LEFT>& event) {
                mouseLook_ = true;
            };

            /**
             * Handles left mouse button release events. Stops mouse looking.
             *
             * @param event The event.
             */
            void handle (const MouseButtonRelease<SDL_BUTTON_LEFT>& event) {
                mouseLook_ = false;
            };

            /**
             * Handles mouse motion events. Changes where the user is looking.
             *
             * @param event The event.
             *
             * @return void.
             */
            void handle (const MouseMotion& event) {
                if (mouseLook_) {
                    xRot_ += event.get ().yrel;
                    if (xRot_ > 360.0f) xRot_ -= 360.0f;
                    if (xRot_ < -360.0f) xRot_ += 360.0f;

                    yRot_ += event.get ().xrel;
                    if (yRot_ > 360.0f) yRot_ -= 360.0f;
                    if (yRot_ < -360.0f) yRot_ += 360.0f;
                }
            };

        private:
            /**
             * Indicates if the program should exit.
             */
            bool& running_;

            /**
             * The viewing location.
             */
            Vector& location_;

            /**
             * The rotation angle around the x axis.
             */
            float& xRot_;

            /**
             * The rotation angle around the y axis. 
             */
            float& yRot_;

            /**
             * Indicates whether or not mouse looking is active.
             */
            bool mouseLook_;
    }; //ExampleHandler
}; //examples
}; //sdl

#endif //SDL_EXAMPLES_EXAMPLEHANDLER_H

