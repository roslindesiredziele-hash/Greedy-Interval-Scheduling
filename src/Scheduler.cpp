#include "Scheduler.h"

#include <algorithm>

using namespace std;

vector<Quest> SelectMaximumQuests(vector<Quest> quests)
{
    sort(quests.begin(), quests.end(), [](const Quest& a, const Quest& b)
        {
            return a.end < b.end
            ? a.start < b.start
            : a.end < b.end;
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