#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Quest.h"
#include <vector>

std::vector<Quest> SelectMaximumQuests(std::vector<Quest>& quests);

std::vector<Quest> GenerateRandomQuests(int n);

#endif