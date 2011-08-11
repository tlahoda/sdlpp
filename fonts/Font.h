/**
 * @file Font.h, Contains the Font class.
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
#ifndef SDL_FONT_H
#define SDL_FONT_H

#include <stdexcept>

#include <SDL_ttf.h>

#include "sdlpp/fonts/Glyph.h"
#include "sdlpp/video/Surface.h"

namespace sdl {
namespace font {
    using namespace std;
    using namespace video;

    /**
     * The different encoding.
     */
    enum Encodings { TEXT, UTF8, UNICODE };

    /**
     * Represents a font.
     */
    struct Font {
        /**
         * Constructs a font, with the given point size, from a file.
         */
        Font (const string& filename, int pointSize) 
          : font_ (TTF_OpenFont (filename.c_str (), pointSize), &TTF_CloseFont) {
            if (font_.get () == 0)
                throw runtime_error (TTF_GetError ());
        };

        /**
         * Destroys the Font.
         */
        ~Font () {
        };

        /**
         * Returns a Surface containg the text rendered in the render mode.
         *
         * @tparam Encoding, The string encoding.
         * @tparam RenderMode, The mode to use in rendering.
         *
         * @param const string& text, The string to render.
         * @param const RenderMode& mode, The mode to use in rendering.
         *
         * @return Surface, The rendered Surface.
         */
        template<int Encoding, class RenderMode>
        Surface render (const string& text, const RenderMode& mode) const {
            return mode.render<Encoding> (*this, text);
        };

        /**
         * Returns the size of the text as it would be rendered.
         *
         * @tparam Encoding, The string encoding.
         *
         * @param const string& text, The text.
         * @param int* height, The rendered height.
         * @param int* width, The rendered width.
         *
         * @return void.
         */
        template<int Encoding>
        void size (const string& text, int* height, int* width) const {
            TTF_SizeText (font_.get (), text.c_str (), width, height);
        };

        /**
         * Returns a Glyph of c.
         *
         * @param char c, The character to render.
         *
         * @return Glyph, A Glyph containing the character.
         */
        Glyph glyph (char c) const {
            return Glyph (*this, c);
        };

        /**
         * Returns the underlying TTF_Font structure.
         *
         * @return TTF_Font*, The underlying TTF_Font structure.
         */
        TTF_Font* operator* () const {
            return font_.get ();
        };

        /**
         * Returns the font height.
         *
         * @return int, The height.
         */
        int height () const {
            return TTF_FontHeight (font_.get ());
        };

        /**
         * Returns the maximum pixel ascent of all Glyphs of the font.
         *
         * @return int, The maximum pixel ascent.
         */
        int ascent () const {
            return TTF_FontAscent (font_.get ());
        };

        /**
         * Returns the maximum pixel descent of all Glyphs of the font.
         *
         * @return int, The maximum pixel descent.
         */
        int descent () const {
            return TTF_FontDescent (font_.get ());
        };

        /**
         * Returns the recommended pixel height of a line of text for the font.
         *
         * @return int, The recommended line height.
         */
        int lineSkip () const {
            return TTF_FontLineSkip (font_.get ());
        };

        private:
            /**
             * The TTF_Font structure.
             */
            boost::shared_ptr<TTF_Font> font_;
    }; //Font

    /**
     * UTF8 specialization. Returns the size of the text as it would be rendered.
     *
     * @tparam Encoding, The string encoding.
     *
     * @param const string& text, The text.
     * @param int* height, The rendered height.
     * @param int* width, The rendered width.
     *
     * @return void.
     */
    template<>
    void Font::size<UTF8> (const string& text, int* height, int* width) const {
        TTF_SizeUTF8 (font_.get (), text.c_str (), width, height);
    };

    /*template<>
    void Font::sizeText<UNICODE> (const string& text, int* height, int* width) const {
        TTF_SizeUNICODE (font_.get (), text.c_str (), width, height);
    };*/
}; //font
}; //sdl

#endif //SDL_FONT_H

