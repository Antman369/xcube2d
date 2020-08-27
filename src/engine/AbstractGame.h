#ifndef __ABSTRACT_GAME_H__
#define __ABSTRACT_GAME_H__

#include "XCube2d.h"
#include "AchievementSystem.h"

class AbstractGame {
	private:
		void handleMouseEvents();
		void updatePhysics();
		void updateAchievements();

		//the next completed achievement to be displayed
		AchievementSystem::AchievementEntry displayAchievement;
		//timer to decide how long achievement is displayed for
		int displayAchievementTimer;

	protected:
		AbstractGame();
		virtual ~AbstractGame();

		/* Engine systems */
		std::shared_ptr<GraphicsEngine> gfx;
		std::shared_ptr<AudioEngine> sfx;
		std::shared_ptr<EventEngine> eventSystem;
		std::shared_ptr<PhysicsEngine> physics;
		std::shared_ptr<AchievementSystem> achievements;

		/* Main loop control */
		bool running;
        bool paused;
		double gameTime;

		virtual void handleKeyEvents() = 0;

		virtual void onLeftMouseButton();
		virtual void onRightMouseButton();

		virtual void update() = 0;
		virtual void render() = 0;

		virtual void renderUI();

		void pause()  { paused = true;  }
		void resume() { paused = false; }
	public:
		int runMainLoop();
};

#endif