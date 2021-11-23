//
// event.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _event_h_
#define _event_h_

#include <SDL.h>

namespace engine {
	enum EventType {
		FIRST = SDL_FIRSTEVENT,     /**< Unused (do not remove) */
		
		/* Application events */
		QUIT = SDL_QUIT, /**< User-requested quit */
		
		/* Window events */
		WINDOW = SDL_WINDOWEVENT, /**< Window state change */
		SYSWM = SDL_SYSWMEVENT,             /**< System specific event */
		
		/* Keyboard events */
		KEYDOWN = SDL_KEYDOWN, /**< Key pressed */
		KEYUP = SDL_KEYUP,                  /**< Key released */
		TEXTEDITING = SDL_TEXTEDITING,            /**< Keyboard text editing (composition) */
		TEXTINPUT = SDL_TEXTINPUT,              /**< Keyboard text input */
		
		/* Mouse events */
		MOUSEMOTION = SDL_MOUSEMOTION, /**< Mouse moved */
		MOUSEBUTTONDOWN = SDL_MOUSEBUTTONDOWN,        /**< Mouse button pressed */
		MOUSEBUTTONUP = SDL_MOUSEBUTTONUP,          /**< Mouse button released */
		MOUSEWHEEL = SDL_MOUSEWHEEL,             /**< Mouse wheel motion */
		
		/* Joystick events */
		JOYAXISMOTION = SDL_JOYAXISMOTION, /**< Joystick axis motion */
		JOYBALLMOTION = SDL_JOYBALLMOTION,          /**< Joystick trackball motion */
		JOYHATMOTION = SDL_JOYHATMOTION,           /**< Joystick hat position change */
		JOYBUTTONDOWN = SDL_JOYBUTTONDOWN,          /**< Joystick button pressed */
		JOYBUTTONUP = SDL_JOYBUTTONUP,            /**< Joystick button released */
		JOYDEVICEADDED = SDL_JOYDEVICEADDED,         /**< A new joystick has been inserted into the system */
		JOYDEVICEREMOVED = SDL_JOYDEVICEREMOVED,       /**< An opened joystick has been removed */
		
		/* Game controller events */
		CONTROLLERAXISMOTION = SDL_CONTROLLERAXISMOTION, /**< Game controller axis motion */
		CONTROLLERBUTTONDOWN = SDL_CONTROLLERBUTTONDOWN,          /**< Game controller button pressed */
		CONTROLLERBUTTONUP = SDL_CONTROLLERBUTTONUP,            /**< Game controller button released */
		CONTROLLERDEVICEADDED = SDL_CONTROLLERDEVICEADDED,         /**< A new Game controller has been inserted into the system */
		CONTROLLERDEVICEREMOVED = SDL_CONTROLLERDEVICEREMOVED,       /**< An opened Game controller has been removed */
		CONTROLLERDEVICEREMAPPED = SDL_CONTROLLERDEVICEREMAPPED,      /**< The controller mapping was updated */
		
		/* Touch events */
		FINGERDOWN = SDL_FINGERDOWN,
		FINGERUP = SDL_FINGERUP,
		FINGERMOTION = SDL_FINGERMOTION,
		
		/* Gesture events */
		DOLLARGESTURE = SDL_DOLLARGESTURE,
		DOLLARRECORD = SDL_DOLLARRECORD,
		MULTIGESTURE = SDL_MULTIGESTURE,
		
		/* Clipboard events */
		CLIPBOARDUPDATE = SDL_CLIPBOARDUPDATE, /**< The clipboard changed */
		
		/* Drag and drop events */
		DROPFILE = SDL_DROPFILE, /**< The system requests a file open */
		
		/** Events ::SDL_USEREVENT through ::SDL_LASTEVENT are for your use,
		*  and should be allocated with SDL_RegisterEvents()
		*/
		USEREVENT = SDL_USEREVENT,
		
		/**
		*  This last event is only for bounding internal arrays
		*/
		LASTEVENT = SDL_LASTEVENT
	};
	
	class Event {
	public:
		Event() = default;
        ~Event() = default;
    public:
		bool PollEvent();
		
		Event(const Event&) = delete;
		Event(Event&&) = delete;
		
		Event& operator=(const Event&) = delete;
		Event& operator=(Event&&) = delete;
		
		[[nodiscard]] Uint32 Type() const;
	private:
		SDL_Event event_;
	};
}

#endif
