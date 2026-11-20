#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include "Scheduler.h"

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

double MeasureScheduler(int n, int repetitions);

void RunExample();

int main()
{
    srand(time(nullptr));
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


double MeasureScheduler(int n, int repetitions)
{
    vector<Quest> quests =
        GenerateRandomQuests(n);

    LARGE_INTEGER start, end, frequency;

    QueryPerformanceFrequency(&frequency);

    double totalTime = 0.0;

    for (int i = 0; i < repetitions; i++)
    {
        QueryPerformanceCounter(&start);

        SelectMaximumQuests(quests);

        QueryPerformanceCounter(&end);

        totalTime +=
            (end.QuadPart - start.QuadPart)
            * 1000.0
            / frequency.QuadPart;
    }

    return totalTime / repetitions;
}


