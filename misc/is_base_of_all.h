/**
 * @file is_base_of_all.h
 * Contains the is_base_of_all class.
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
#ifndef SDL_MISC_IS_BASE_OF_ALL_H
#define SDL_MISC_IS_BASE_OF_ALL_H

#include <SDL.h>

#include <boost/type_traits/is_base_of.hpp>

namespace sdl {
namespace misc {
    /**
     * @struct is_base_of_all
     * @brief Recursively determines if Base is the base of all of the Ts.
     *
     * @tparam Base The type of the Base to check against.
     * @tparam Ts The types to check.
     */
    template<typename Base, typename... Ts>
    struct is_base_of_all {}; //is_base_of_all

    /**
     * @struct is_base_of_all
     * @brief The recursion's terminal specialization.
     *
     * @tparam Base The type of the Base to check against.
     */
    template<typename Base>
    struct is_base_of_all<Base> {
        /**
         * The value of the terminal check. Defaults to true otherwise the recursion will never evaluate to true.
         */
        const static bool value = true; 
    }; //is_base_of_all

    /**
     * @struct is_base_of_all
     * @brief The main specialization the determines if Base is the Base of the Ts.
     *
     * @tparam Base The type of the Base to check against.
     * @tparam T The type to check.
     * @tparam Ts The types to check.
     */
    template<typename Base, typename T, typename... Ts>
    struct is_base_of_all<Base, T, Ts...> {
        /**
         * The value of the recursive check.
         */
        const static bool value = boost::is_base_of<Base, T>::value && is_base_of_all<Base, Ts...>::value;
    }; //is_base_of_all
}; //misc
}; //sdl

#endif //SDL_MISC_IS_BASE_OF_ALL_H

