#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>

#include "EngineCommon.h"

class AchievementSystem
{
public:
	struct AchievementEntry
	{
		std::string title, description;
	};

	void set(std::unordered_map<std::string, AchievementEntry> achievementList)
	{
		achievements = achievementList;
	}

	bool gain(std::string achievementId)
	{
		if (achievements.find(achievementId) == end(achievements))
			throw std::out_of_range(achievementId);
		bool newlyGained = completed.find(achievementId) == end(completed);
		completed.insert(achievementId);

#ifdef __DEBUG
		if (newlyGained)
		{
			debug("gained ", achievementId.c_str());
		}
#endif

		return newlyGained;
	}

private:
	std::unordered_map<std::string, AchievementEntry> achievements;
	std::unordered_set<std::string> completed;

	
};