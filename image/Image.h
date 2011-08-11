/**
 * @file Image.h, Contains the Image class.
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
#ifndef SDL_IMAGE_IMAGE_H
#define SDL_IMAGE_IMAGE_H

#include <SDL_image.h>

#include "sdlpp/video/Surface.h"

namespace sdl {
namespace image {
    using namespace std;
    using namespace video;

    /**
     * @struct Image, Representsan image.
     */
    struct Image {
        /**
         * Constructs an Image.
         *
         * @param const string& file, The name of the image file.
         */
        Image (const string& file) : file_ (file) {};

        /**
         * Renders the image onto a Surface.
         *
         * @return Surface, The Surface.
         */
        Surface render () const { return Surface (IMG_Load (file_.c_str ())); };

        private:
            /**
             * The name of the image file.
             */
            string file_;
    }; //Image
}; //image
}; //sdl

#endif //SDL_IMAGE_IMAGE_H

