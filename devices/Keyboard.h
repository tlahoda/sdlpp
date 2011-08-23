/**
 * @file Keyboard.h, Contains the Keyboard class.
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
#ifndef SDL_DEVICES_KEYBOARD_H
#define SDL_DEVICES_KEYBOARD_H

#include <utility>

namespace sdl {
namespace devices {
    using namespace std;

    /**
     * @struct Keyboard, Represents a keyboard.
     */
    struct Keyboard {
        /**
         * Gets the name of the SDL virtual keysym.
         *
         * @param SDLKey key, The key for which to get the name of the keysym.
         *
         * @return string, The name of the keysym.
         */
        static string getKeyName (SDLKey key) { return SDL_GetKeyName (key); };

        /**
         * Gets the current keyboard state.
         *
         * @return pair<unsignedchar*, int>, A pair containing an array of the current keyboard state and its length.
         */
        static pair<unsigned char*, int> keyState () {
            int numKeys;
            unsigned char* keys = SDL_GetKeyState (&numKeys);
            return make_pair (keys, numKeys);
        };

        /**
         * Gets the state of the modifier keys.
         *
         * @return SDLMod, The state of the modifier keys.
         */
        static SDLMod getModState () {  return SDL_GetModState (); };

        /**
         * Sets the state of the modifier keys.
         *
         * @param SDLMod state, The state to which to set the modifier keys.
         *
         * @return void.
         */
        static void setModState (SDLMod state) { SDL_SetModState (state); };

        /**
         * Enables key repeating.
         *
         * @param int delay, The number of milliseconds the key must be pressed before it starts repeating.
         * @param int interval, The interval in milliseconds at which to reapeat the keys.
         *
         * @return bool, True if successful, false otherwise.
         */
        static bool enableKeyRepeat (int delay, int interval) { return SDL_EnableKeyRepeat (delay, interval) == 0; };

        /**
         * Disables key repeating.
         *
         * @return bool, True if successful, false otherwise.
         */
        static bool disableKeyRepeat () { return SDL_EnableKeyRepeat (0, 0) == 0;};

        /**
         * Enables UNICODE translation.
         *
         * @return void.
         */
        static void enableUnicode () { SDL_EnableUNICODE (1); };

        /**
         * Disables UNICODE translation.
         *
         * @return void.
         */
        static void disableUnicode () { SDL_EnableUNICODE (0); };

        /**
         * Determines if UNICODE translation is enabled.
         *
         * @return bool, True if enabled, false otherwise.
         */
        static bool unicodeEnabled () { return SDL_EnableUNICODE (-1) == 1; };
    }; //Keyboard
}; //devices
}; //sdl

#endif //SDL_DEVICES_KEYBOARD_H

