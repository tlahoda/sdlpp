/**
 * @file SharedObject.h, Contains the SharedObject class.
 *
 * Copyright (C) 2011 Thomas P. Lahoda
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
#ifndef SDL_MISC_SHAREDOBJECT_H
#define SDL_MISC_SHAREDOBJECT_H

#include <string>

#include <SDL_loadso.h>

namespace sdl {
namespace misc {
    /**
     * @struct SharedObject, Represents a shared object.
     */
    struct SharedObject {
        /**
         * Loads a shared object from a file.
         *
         * @param const string& fileName, The file from which to load the shared object.
         */
        SharedObject (const string& fileName) : handle_ (SDL_LoadObject (fileName.c_str ())) {};

        /**
         * Unloads the shared object.
         */
        ~SharedObject () { SDL_UnloadObject (handle_); };

        /**
         * Returns the address of a function in a loaded shared object.
         *
         * @param void* handle, The valid shared object handle.
         * @param const string& name, The function's name.
         *
         * @return void*, The pointer to the function on success, NULL otherwise.
         */
        void* loadFunction (const string& name) {
            return SDL_LoadFunction (handle_, name.c_str ());
        };

        private:
            /**
             * Copy constructs a SharedObject.
             *
             * @param const SharedObject& rhs, The SharedObject to copy.
             */
            SharedObject (const SharedObject& rhs);

            /**
             * The assignment operator.
             *
             * @param const SharedObject& rhs, The SharedObject from which to assign.
             *
             * @return SharedObject&, A reference to this SharedObject.
             */
            SharedObject& operator= (const SharedObject& rhs);

            /**
             * The handle to the shared object.
             */
            void* handle_;
    }; //SharedObject
}; //misc
}; //sdl

#endif //SDL_MISC_SHAREDOBJECT_H

