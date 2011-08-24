/**
 * @file Color.h
 * Contains the Color class.
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
#ifndef SDL_MISC_COLOR_H
#define SDL_MISC_COLOR_H

#include <boost/shared_ptr.hpp>

#include <SDL.h>

namespace sdl {
namespace misc {
    /**
     * @class Color
     * @brief Represents an RGBA color.
     */
    class Color {
        public:
            /**
             * Constructs a Color from a SDL_Color structure.
             *
             * @param c The SDL_Color structure.
             */
            Color (SDL_Color* c) : color_ (c) {};

            /**
             * Constructs a Color.
             *
             * @param red, The red intensity.
             * @param green, The green intensity.
             * @param blue, The blue intensity.
             * @param alpha, The alpha intensity.
             */
            Color (unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
                : color_ (new SDL_Color ()) {
                color_->r = red;
                color_->g = green;
                color_->b = blue;
                color_->unused = alpha;
            };

            /*
             * Return the underlying SDL_Color structure.
             *
             * @return The SDL_Color structure.
             */
            SDL_Color* operator* () const { 
                return color_.get (); 
            };

            /**
             * Returns the red intensity.
             *
             * @return The red intensity.
             */
            unsigned char red () const { 
                return color_->r; 
            };

            /**
             * Sets the red intensity.
             *
             * @param r The red intensity.
             *
             * @return A reference to this Color.
             */
            Color& red (unsigned char r) {
                color_->r = r;
                return *this; 
            };

            /**
             * Returns the green intensity.
             *
             * @return The green intensity.
             */
            unsigned char green () const { 
                return color_->g; 
            };

            /**
             * Sets the green intensity.
             *
             * @param g The green intensity.
             *
             * @return A reference to this Color.
             */
            Color& green (unsigned char g) { 
                color_->g = g;
                return *this; 
            };

            /**
             * Returns the blue intensity.
             *
             * @return The blue intensity.
             */
            unsigned char blue () const { 
                return color_->b; 
            };

            /**
             * Sets the blue intensity.
             *
             * @param The blue intensity.
             *
             * @return A reference to this Color.
             */
            Color& blue (unsigned char b) { 
                color_->b = b;
                return *this; 
            };

            /**
             * Returns the alpha intensity.
             *
             * @return The alpha intensity.
             */
            unsigned char alpha () const { 
                return color_->unused; 
            };

            /**
             * Sets the alpha intensity.
             *
             * @return A reference to this Color.
             */
            Color& alpha (unsigned char a) { 
                color_->unused = a;
                return *this; 
            };

        private:
            /*
             * The SDL_Color structure.
             */
            boost::shared_ptr<SDL_Color> color_;
    }; //Color
}; //misc
}; //sdl

#endif //SDL_MISC_COLOR_H

