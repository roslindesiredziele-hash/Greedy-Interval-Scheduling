#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <Windows.h>

#include "Scheduler.h"

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

    RunExample();

    ofstream outfile("./data/benchmark.csv");

    if (!outfile)
    {
        cerr<< "Unable to open benchmark.csv\n";
        return 1;
    }

    outfile << "Size," << "TimeMs\n";

    vector<int> sizes =
    {
        10,
        20,
        30,
        40,
        50,
        100,
        150,
        200,
        250,
        300,
        400,
        500,
        1000,
        1500,
        2000,
        2500,
        3000,
        5000,
        10000,
        100000,
        1000000
    };

    for (int size : sizes)
    {
        int repetitions;

        if (size <= 1000)
        {
            repetitions = 100;
        }
        else if (size <= 100000)
        {
            repetitions = 20;
        }
        else
        {
            repetitions = 5;
        }

        double time = MeasureScheduler(size, repetitions);

        cout << "Size: " << size << " | Time: " << time << " ms" << endl;

        outfile << size << "," << time << "\n";
    }

    outfile.close();

    cout << "\nBenchmark completed.\n";

    cout << "Results saved to " << "./data/benchmark.csv\n";

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

        totalTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
    }

    return totalTime / repetitions;
}

void RunExample()
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

    vector<Quest> result = SelectMaximumQuests(quests);

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
        << "\n\n";
}
