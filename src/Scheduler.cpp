#include "Scheduler.h"

#include <algorithm>
#include <ctime>

using namespace std;

vector<Quest> SelectMaximumQuests(vector<Quest>& quests)
{
    sort(quests.begin(), quests.end(), [](const Quest& a, const Quest& b)
        {
            if (a.end != b.end)
            {
                return a.end < b.end;
            }
            
            return a.start < b.start;
        }
    );

    vector<Quest> chosen;

    int currentEnd = -1;

    for (const Quest& q : quests)
    {
        if (q.start >= currentEnd)
        {
            chosen.push_back(q);
            currentEnd = q.end;
        }
    }
    
    return chosen;
}

vector<Quest> GenerateRandomQuests(int n)
{
    vector<Quest> quests;

    srand(time(nullptr));

    for (int i = 0; i < n; i++)
    {
        int start = rand() % 100000;

        int duration =
            1 + rand() % 100;

        int end =
            start + duration;

        quests.push_back(
        {
            start,
            end
        });
    }

    return quests;
}