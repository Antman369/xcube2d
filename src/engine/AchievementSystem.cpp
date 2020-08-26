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

#ifdef __DEBUG
	if (newlyGained)
	{
		debug("gained ", achievementId.c_str());
	}
#endif

	return newlyGained;
}