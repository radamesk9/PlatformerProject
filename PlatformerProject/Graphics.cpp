

#include "Graphics.h"
#include "SDL.h"
/*aqui vai ficar toda a informação de graficos do jogo e headers vinculados;

*/
Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_Window, &this->_Renderer);
	SDL_SetWindowTitle(_Window, "Captain America");

}
Graphics::~Graphics() {
	SDL_DestroyWindow(_Window);
}