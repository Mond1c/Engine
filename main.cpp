#include "engine.h"

int main(int argc, char* argv[]) {
	Engine engine;
	
	engine.Start();
	
	while (true) {
		engine.Update();
		SDL::Event event;
		if (event.PollEvent()) {
			if (event.Type() == SDL::EventType::QUIT) {
				break;
			}
		}
		SDL::Delay(DELAY);
	}
	SDL_Quit();
	return 0;
}
