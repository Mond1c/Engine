//
// event.h
// Created by Mihail Kornilovich on 22.08.2021.
#pragma once

#ifndef _event_h_
#define _event_h_

#include <SDL2/SDL.h>

namespace SDL {
	enum EventType {
		QUIT = SDL_QUIT
	};
	
	class Event {
	public:
		Event() = default;
		bool PollEvent();
		
		Uint32 Type() const;
	private:
		SDL_Event event_;
	};
}

#endif