#include "Scheduler.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Quest> quests =
    {
        {1, 4},
        {1, 3},
        {2, 5},
        {4, 7},
        {6, 9},
        {8, 10},
        {11, 13},
        {3, 5},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    vector<Quest> result =
        SelectMaximumQuests(quests);

    cout << "Selected quests:\n";

    for (const Quest& q : result)
    {
        cout
            << "["
            << q.start
            << ", "
            << q.end
            << ")\n";
    }

    cout
        << "\nTotal quests: "
        << result.size()
        << endl;

    return 0;
}