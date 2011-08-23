##
 # @file Makefile, Contains the build instructions.
 #
 # Copyright (C) 2005 Thomas P. Lahoda
 #
 # This library is free software; you can redistribute it and/or
 # modify it under the terms of the GNU Lesser General Public
 # License as published by the Free Software Foundation; either
 # version 2.1 of the License, or (at your option) any later version.
 #
 # This library is distributed in the hope that it will be useful,
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 # Lesser General Public License for more details.
 #
 # You should have received a copy of the GNU Lesser General Public
 # License along with this library; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
##
BASE_DIR=usr

SDL_INC=-I/$(BASE_DIR)/include/SDL
SDL_LIB=-L/$(BASE_DIR)/lib -lSDL -lSDLmain
SDLPP_INC=-I../../.

BOOST_INC=-I/$(BASE_DIR)/include
BOOST_LIB=-L/$(BASE_DIR)/lib 

OPENGL_LIB=/$(BASE_DIR)/lib/libGL.so
GLU_LIB=/$(BASE_DIR)/lib/libGLU.so

X11_INC=-I/usr/X11/include

all: example

example: example.cpp
	g++ -O5 -Wall -std=gnu++0x example.cpp $(X11_INC) $(SDL_INC) $(BOOST_INC) $(SDLPP_INC) $(SDL_LIB) $(BOOST_LIB) $(OPENGL_LIB) $(GLU_LIB) -o example 
	strip example

clean:
	rm -f example

