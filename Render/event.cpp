//
// event.cpp
// Created by Mihail Kornilovich on 22.08.2021.

#include "event.h"
using namespace SDL;

bool Event::PollEvent() {
	return SDL_PollEvent(&event_);
}

Uint32 Event::Type() const {
	return event_.type;
}