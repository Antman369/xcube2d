#ifndef __TEST_GAME_H__
#define __TEST_GAME_H__

#include "../engine/AbstractGame.h"

#include "TestMazeGenerator.h"

struct SDL_Image;

struct GameKey {
	Point2 pos;
	bool alive;
};

class TestGame : public AbstractGame {
	private:
		Rect box;
		Rect light;

		Vector2i velocity;
		Vector2i facing;
		SDL_Texture* playerSprite;
		int playerAnimFrame = 0;
		int playerAnimTimer = 0;

		MazeGenerator * gen;

		std::vector<std::shared_ptr<Line2i>> lines;
		std::vector<std::shared_ptr<GameKey>> points;


		/* GAMEPLAY */
		int score, keys, lives;
		bool gameWon;

		void updatePlayerFrame();
		void handleKeyEvents();
		void update();
		void render();
		void drawPlayer();
		void renderUI();
	public:
		TestGame();
		~TestGame();
};

#endif