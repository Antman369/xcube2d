#include "AchievementSystem.h"

using namespace std;

//function to set the achievements for the specfic game
void AchievementSystem::add(string id, string name, string description)
{
	achievements[id] = { name, description };
}

//function to check if an achievement has been gained
bool AchievementSystem::gain(string achievementId)
{
	if (achievements.find(achievementId) == end(achievements))
		throw out_of_range(achievementId);
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

//function to check if there is an achievement to be displayed next
bool AchievementSystem::checkNextDisplayAchievement()
{
	return !nextDisplayAchievements.empty();
}

//function to get the achievement that needs to be displayed next
AchievementSystem::AchievementEntry AchievementSystem::getNextDisplayAchievement() 
{
	auto result = nextDisplayAchievements.front();
	nextDisplayAchievements.pop();
	return result;
}