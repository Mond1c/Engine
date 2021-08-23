

#include "engine.h"

int main(int argc, char* argv[]) {
	Engine engine;
	
	engine.Start();
	
	while (true) {
		//	engine.Update();
		SDL::Event event;
		if (event.PollEvent()) {
			if (event.Type() == SDL::EventType::QUIT) {
				break;
			}
		}
		SDL::Delay(DELAY);
	}
	return 0;
}

//int main(int argc, char* argv[]) {
//	Window window("Window", Vector(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED), Vector(WIDTH, HEIGHT), SDL_WINDOW_SHOWN);
//	Renderer renderer(window.Ptr(), -1, SDL_RENDERER_ACCELERATED);
//	renderer.SetColor(Color(255, 255, 255, 255));
//	renderer.Clear();
//	renderer.SetColor(Color(0, 0, 0));
//	renderer.Update();
//	
//	while (true) {
//		Event event;
//		if (event.PollEvent()) {
//			if (event.Type() == EventType::QUIT) break;
//		}
//		Delay(DELAY);
//	}
//	return 0;
//}