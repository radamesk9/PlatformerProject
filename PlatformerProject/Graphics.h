#ifndef GRAPHICS_H
#define GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
private:
	SDL_Window* _Window;
	SDL_Renderer* _Renderer;
};

#endif // !graphics_h
#pragma once
