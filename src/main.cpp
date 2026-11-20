#include "Scheduler.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Quest> quests =
    {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    vector<Quest> result =
        SelectMaximumQuests(uests);

    cout << "Selected quests:\n";

   

    return 0;
}