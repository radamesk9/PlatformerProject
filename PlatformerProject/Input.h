#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <map>

class Input {
public:
	void BeginNewFrame();
	void KeyUpEvent(const SDL_Event& event); //quando uma tecla é apertada
	void KeyDownEvent(const SDL_Event& event);//quando uma tecla é solta

	bool WasKeyPressed(SDL_Scancode key);//qual tecla foi apertada
	bool WasKeyReleased(SDL_Scancode key);//qual tecla foi solta
	bool isKeyHold(SDL_Scancode key);//qual tecla está sendo apertada no momento
private:
	std::map<SDL_Scancode, bool> _HoldKeys;
	std::map<SDL_Scancode, bool> _PressedKeys;
	std::map<SDL_Scancode, bool> _ReleasedKeys;
};

#endif // !INPUT_H
