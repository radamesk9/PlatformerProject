#include "SDL.h"
#include "Game.h"
#include "Graphics.h"
#include "Input.h"
#include <algorithm> //por causa de std::min tivemos que incluir essa biblioteca.

/*aqui � onde as rotinas iniciais do jogo v�o rodar, onde ir�o ficar os loops das janelas
*/
//inicializa todas as instancias do jogo, controles, audio, video, classes, etc.
namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}


Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->GameLoop();
}

Game::~Game() {

}

void Game::GameLoop() {
	Graphics Graphics;
	Input Input;
	SDL_Event Event;

	int LAST_UPDATE_TIME = SDL_GetTicks();//come�a a contar quantos milisegundos demorou pra correr toda a fun��o.

	//� aqui que o fun��o come�a.
	while (true){
		Input.BeginNewFrame();
		if (SDL_PollEvent(&Event)) {
			if (Event.type == SDL_KEYDOWN) {
				if (Event.key.repeat == 0) {
					Input.KeyDownEvent(Event);
				}
				else if (Event.type == SDL_KEYUP) {
					Input.KeyUpEvent(Event);
				}
			}
			else if (Event.type == SDL_QUIT) {
				return; //isso acontece quando voc� clica em x pra sair do programa ou quando voc� termina o jogo.
			}
		}
		if (Input.WasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		//Essa fun�ao � a que deixa travado em 50 FPS, come�a l� em cima, em namespace
		const int CURRENT_TIME_MS = SDL_GetTicks(); //termina de contar quantos milisegundos demorou pra correr a fun��o
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Game::Draw(Graphics &Graphics) {

}

void Game::update(float elapsedtime) {

}