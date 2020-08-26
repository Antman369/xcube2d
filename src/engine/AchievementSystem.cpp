#include "AchievementSystem.h"

void AchievementSystem::set(std::unordered_map<std::string, AchievementEntry> achievementList)
{
	achievements = achievementList;
}

bool AchievementSystem::gain(std::string achievementId)
{
	if (achievements.find(achievementId) == end(achievements))
		throw std::out_of_range(achievementId);
	bool newlyGained = completed.find(achievementId) == end(completed);
	completed.insert(achievementId);

	if (newlyGained)
	{
		nextDisplayAchievements.push(achievements[achievementId]);
#ifdef __DEBUG
		debug("gained ", achievementId.c_str());
#endif
	}

	return newlyGained;
}

bool AchievementSystem::checkNextDisplayAchievement()
{
	return !nextDisplayAchievements.empty();
}

AchievementSystem::AchievementEntry AchievementSystem::getNextDisplayAchievement() 
{
	auto result = nextDisplayAchievements.front();
	nextDisplayAchievements.pop();
	return result;
}