/**
 * @file Icon.h, Contains the Icon class.
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
#ifndef SDL_VIDEO_ICON_H
#define SDL_VIDEO_ICON_H

#include <string>

namespace sdl {
namespace video {
    using namespace std;

    /**
     * @class Icon, Represents an icon.
     */
    class Icon {
        public:
            /**
             * Constructs an Icon with a name.
             *
             * @param const string& name, The icon name.
             */
            Icon (const string& name) : name_ (name) {};

            /**
             * Destroys the Icon.
             */
            ~Icon () {};

            /**
             * Returns the name of the icon.
             *
             * @return string, The name of the icon.
             */
            string name () const { return name_; };

            /**
             * Set the Icon name.
             *
             * @param const string& name, The name to give the icon.
             *
             * @return Icon, A reference to this Icon.
             */
            Icon& name (const string& name) {
                name_ = name;
                return *this;
            };

        private:
            /*
             * The name of the icon.
             */
            string name_;
    }; //Icon
}; //video
}; //sdl

#endif //SDL_VIDEO_ICON_H

