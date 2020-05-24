#ifndef GAME_H
#define GAME_H

class Graphics;

class Game {
public:
	Game();
	~Game();
	void Draw();
private:
	void GameLoop();
	void Draw(Graphics &Graphics);
	void update(float elapsedtime);
};
#endif // !GAME_H