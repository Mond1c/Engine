#include "settings.h"
#include "Render/window.h"
#include "Rectangles/shapes.h"
#include "Render/event.h"
using namespace SDL;

const float a = 1;
const float b = -4;
const float c = -5;

int main(int argc, char* argv[]) {
	Window window("Window", Vector(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED), Vector(WIDTH, HEIGHT), SDL_WINDOW_SHOWN);
	Renderer renderer(window.Ptr(), -1, SDL_RENDERER_ACCELERATED);
	renderer.SetColor(Color(255, 255, 255, 255));
	renderer.Clear();
	renderer.SetColor(Color(0, 0, 0));
	for (float x = -WIDTH / 2; x <= WIDTH / 2; x += 0.1f) {
		float y = a * x * x + b * x + c;
		renderer.Draw(Point(Vector(x + WIDTH / 2, -1 * y * 0.1f + HEIGHT / 2)));
	}
	renderer.Update();
	
	while (true) {
		Event event;
		if (event.PollEvent()) {
			if (event.Type() == EventType::QUIT) break;
		}
		Delay(DELAY);
	}
	return 0;
}