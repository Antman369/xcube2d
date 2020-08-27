#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <queue>

#include "EngineCommon.h"

class AchievementSystem
{
public:
	//data structure for all achievement attributes
	struct AchievementEntry
	{
		std::string title, description;
	};

	void add(std::string id, std::string title, std::string description);

	bool gain(std::string achievementId);

	bool checkNextDisplayAchievement();

	AchievementEntry getNextDisplayAchievement();

private:
	//container to store all achievements
	std::unordered_map<std::string, AchievementEntry> achievements;
	//container to store completed achievements
	std::unordered_set<std::string> completed;
	//container to store the completed achievements that need to be displayed
	std::queue<AchievementEntry> nextDisplayAchievements;
};