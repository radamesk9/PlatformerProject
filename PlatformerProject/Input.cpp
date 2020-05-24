#include "Input.h"

//essa função limpa as teclas que ja foram usadas
void Input::BeginNewFrame() {
	this->_PressedKeys.clear();
	this->_ReleasedKeys.clear();
}

//tecla apertada
void Input::KeyDownEvent(const SDL_Event& event) {
	this->_PressedKeys[event.key.keysym.scancode] = true;
	this->_HoldKeys[event.key.keysym.scancode] = true;
}

//tecla solta
void Input::KeyUpEvent(const SDL_Event& event) {
	this->_ReleasedKeys[event.key.keysym.scancode] = true;
	this->_HoldKeys[event.key.keysym.scancode] = false;
}

//faz as checagens se as teclas foram apertadas ou soltas
bool Input::WasKeyPressed(SDL_Scancode key) {
	return this->_PressedKeys[key];
}

//faz as checagens se as teclas foram apertadas ou soltas
bool Input::WasKeyReleased(SDL_Scancode key) {
	return this->_ReleasedKeys[key];
}

//faz a checagem se uma certa tecla está sendo apertada
bool Input::isKeyHold(SDL_Scancode key) {
	return this->_HoldKeys[key];
}