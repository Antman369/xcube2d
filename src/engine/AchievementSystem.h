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
	struct AchievementEntry
	{
		std::string title, description;
	};

	void set(std::unordered_map<std::string, AchievementEntry> achievementList);

	bool gain(std::string achievementId);

	bool checkNextDisplayAchievement();
	AchievementEntry getNextDisplayAchievement();

private:
	std::unordered_map<std::string, AchievementEntry> achievements;
	std::unordered_set<std::string> completed;
	std::queue<AchievementEntry> nextDisplayAchievements;
};