/**
 * @file WindowEvents.h, Contains various application window event classes.
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
#ifndef SDL_EVENT_WINDOWEVENTS_H
#define SDL_EVENT_WINDOWEVENTS_H

#include <SDL.h>

#include "sdlpp/event/SimpleComparator.h"

namespace sdl {
namespace event {
    /**
     * @struct ActiveBase, Base for an active event that exposes the SDL_ActiveEvent structure.
     */
    struct ActiveBase : public EventBase {
        /**
         * Constructs an ActiveBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        ActiveBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_ActiveEvent structure.
         *
         * @return const SDL_ActiveEvent&, The SDL_ActiveEvent structure.
         */
        const SDL_ActiveEvent& get () const { return event_->active; }; 
    
        /**
         * Exposes the SDL_ActiveEvent structure.
         *
         * @return const SDL_ActiveEvent&, The SDL_ActiveEvent structure.
         */
        const SDL_ActiveEvent& get () { return event_->active; };
    }; //Active
    
    /**
     * @typedef Event<SimpleComparator<SDL_ACTIVEEVENT>, ActiveBase> Active,
     *          Represents an application window active event.
     */
    typedef Event<SimpleComparator<SDL_ACTIVEEVENT>, ActiveBase> Active;
    
    /**
     * @struct ExposeBase, Base for an expose event that exposes the SDL_ExposeEvent structure.
     */
    struct ExposeBase : public EventBase {
        /**
         * Constructs an ExposeBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        ExposeBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_ExposeEvent structure.
         *
         * @return const SDL_ExposeEvent&, The SDL_ExposeEvent structure.
         */
        const SDL_ExposeEvent& get () const { return event_->expose; };

        /**
         * Exposes the SDL_ExposeEvent structure.
         *
         * @return const SDL_ExposeEvent&, The SDL_ExposeEvent structure.
         */
        const SDL_ExposeEvent& get () { return event_->expose; };
    }; //Expose
    
    /**
     * @typedef Event<SimpleComparator<SDL_VIDEOEXPOSE>, ExposeBase> Expose,
     *          Represents an application window expose event.
     */
    typedef Event<SimpleComparator<SDL_VIDEOEXPOSE>, ExposeBase> Expose;

    /**
     * @struct QuitBase, Base for a quit event that exposes the SDL_QuitEvent structure.
     */
    struct QuitBase : public EventBase {
        /**
         * Constructs a QuitBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        QuitBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_QuitEvent structure.
         *
         * @return const SDL_QuitEvent&, The SDL_QuitEvent structure.
         */
        const SDL_QuitEvent& get () const { return event_->quit; };

        /**
         * Exposes the SDL_QuitEvent structure.
         *
         * @return const SDL_QuitEvent&, The SDL_QuitEvent structure.
         */
        const SDL_QuitEvent& get () { return event_->quit; };
    }; //Quit
    
    /**
     * @typedef Event<SimpleComparator<SDL_QUIT>, QuitBase> Quit,
     *          Represents an application quit event.
     */
    typedef Event<SimpleComparator<SDL_QUIT>, QuitBase> Quit;

    /**
     * @struct ResizeBase, Base for a resize event that exposes the SDL_ResizeEvent structure.
     */
    struct ResizeBase : public EventBase {
        /**
         * Constructs a ResizeBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        ResizeBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_ResizeEvent structure.
         *
         * @return const SDL_ResizeEvent&, The SDL_ResizeEvent structure.
         */
        const SDL_ResizeEvent& get () const { return event_->resize; };
    
        /**
         * Exposes the SDL_ResizeEvent structure.
         *
         * @return const SDL_ResizeEvent&, The SDL_ResizeEvent structure.
         */
        const SDL_ResizeEvent& get () { return event_->resize; };
    }; //Resize
    
    /**
     * @typedef Event<SimpleComparator<SDL_VIDEORESIZE>, ResizeBase> Resize,
     *          Represents an application window resize event.
     */
    typedef Event<SimpleComparator<SDL_VIDEORESIZE>, ResizeBase> Resize;

    /**
     * @struct, WindowManagerBase, Base for a window manager event that exposes the SDL_SysWMEvent structure.
     */
    struct WindowManagerBase : public EventBase {
        /**
         * Constructs a WindowManagerBase from a SDL_Event structure.
         *
         * @param const SDL_Event* event, The SDL_Event structure.
         */
        WindowManagerBase (const SDL_Event* event) : EventBase (event) {};

        /**
         * Exposes the SDL_SysWMEvent structure.
         *
         * @return const SDL_SysWMEvent&, The SDL_SysWMEvent structure.
         */
        const SDL_SysWMEvent& get () const { return event_->syswm; };
    
        /**
         * Exposes the SDL_SysWMEvent structure.
         *
         * @return const SDL_SysWMEvent&, The SDL_SysWMEvent structure.
         */
        const SDL_SysWMEvent& get () { return event_->syswm; };
    }; //WindowManager

    /**
     * @typedef Event<SimpleComparator<SDL_SYSWMEVENT>, WindowManagerBase> WindowManager,
     *          Represents an undefined window manager event.
     */
    typedef Event<SimpleComparator<SDL_SYSWMEVENT>, WindowManagerBase> WindowManager;
}; //event
}; //sdl

#endif //SDL_EVENT_WINDOWEVENTS_H

