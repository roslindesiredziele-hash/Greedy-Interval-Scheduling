# Pro Publico Bono

A C++ implementation of the classic Activity Selection Problem using a greedy algorithm. The project helps Geralt the Witcher choose the maximum number of non-overlapping community service quests that can be completed within a day.

## Overview

Geralt considers undertaking a set of unpaid community service quests.

Each quest occupies a time interval:

```text
[start, end)
```

Some quests overlap and therefore cannot be completed together.

The objective is to select the maximum possible number of non-overlapping quests.

This problem is solved using a greedy interval scheduling algorithm.

---

## Problem Statement

Given a set of quests:

```text
Q1 = [s1, t1)
Q2 = [s2, t2)
...
Qn = [sn, tn)
```

select the largest subset of mutually non-overlapping quests.

Example:

```text
[1,4)
[3,5)
[0,6)
[5,7)
[8,9)
[5,9)
```

Optimal solution:

```text
[1,4)
[5,7)
[8,9)
```

Total quests completed:

```text
3
```

---

## Data Structure

Each quest is represented by:

```cpp
struct Quest
{
    int start;
    int end;
};
```

---

## Algorithm

### Greedy Interval Scheduling

The algorithm follows a well-known greedy strategy:

1. Sort all quests by increasing finishing time.
2. Select the quest that finishes earliest.
3. Repeatedly select the next quest whose start time is not earlier than the end time of the previously selected quest.

Implementation:

```cpp
sort(
    quests.begin(),
    quests.end(),
    ...
);

for (const Quest& q : quests)
{
    if (q.start >= currentEnd)
    {
        chosen.push_back(q);
        currentEnd = q.end;
    }
}
```

---

## Correctness

The greedy choice is optimal because selecting the quest that finishes earliest leaves the largest possible amount of time available for future quests.

Therefore, no other choice can lead to a larger set of compatible quests.

---

## Complexity Analysis

Sorting:

```text
O(n log n)
```

Selection:

```text
O(n)
```

Overall:

```text
O(n log n)
```

Space Complexity:

```text
O(n)
```

---

## Benchmarking Methodology

Execution time was measured using:

```cpp
QueryPerformanceCounter()
```

from the Windows API.

Random quest datasets were generated using:

```cpp
GenerateRandomQuests(int n)
```

Quest sizes:

```text
10
20
30
40
50
100
150
200
250
300
400
500
1000
1500
2000
2500
3000
5000
10000
100000
1000000
```

Average execution time was recorded for each dataset size.

---

## Experimental Results

Example benchmark results:

| Number of Quests | Time (ms) |
|------------------|------------|
| 10 | 0.0015 |
| 100 | 0.0079 |
| 1000 | 0.1287 |
| 10000 | 1.6469 |
| 100000 | 20.4165 |
| 1000000 | 276.483 |

The measured execution times grow consistently with the expected:

```text
O(n log n)
```

complexity.

The sorting phase dominates the runtime, while the greedy selection phase requires only a linear scan.

---

## Generated Figures

### Runtime Comparison

```text
report/runtime_comparison.png
```

Displays execution time as a function of the number of quests.

### Logarithmic Runtime Comparison

```text
report/runtime_logarithmic.png
```

Uses logarithmic axes to better visualize growth trends over large input sizes.

---

## Setup

### Prerequisites

- C++17 compatible compiler
- Windows operating system
- Python 3.13+ (for graph generation)

---

## Build

```bash
g++ src/main.cpp src/Scheduler.cpp -o benchmark
```

---

## Usage

Run:

```bash
./benchmark.exe
```

The program:

1. Demonstrates the algorithm on a sample dataset.
2. Generates random quest datasets.
3. Measures execution time.
4. Saves benchmark data.

Example output:

```text
Selected quests:
[1, 3)
[3, 5)
[5, 7)
[8, 9)
[11, 13)

Total quests: 5

Size: 1000 | Time: 0.128 ms
Size: 10000 | Time: 1.647 ms
...
```

---

## Benchmark Output

Results are stored in:

```text
data/benchmark.csv
```

Format:

```csv
Size,TimeMs
10,0.0015
20,0.0027
...
1000000,276.483
```

---

## Generate Graphs

Install dependencies:

```bash
py -3.13 -m pip install pandas matplotlib
```

Run:

```bash
py -3.13 graph.py
```

Generated files:

```text
report/
├── runtime_comparison.png
└── runtime_logarithmic.png
```

---

## Project Structure

```text
task2_Pro_publico_bono
│
├── data/
│   └── benchmark.csv
│
├── report/
│   ├── runtime_comparison.png
│   └── runtime_logarithmic.png
│
├── src/
│   ├── Quest.h
│   ├── Scheduler.h
│   ├── Scheduler.cpp
│   └── main.cpp
│
├── graph.py
├── README.md
└── benchmark.exe
```

---

## Conclusion

A greedy interval scheduling algorithm was implemented to maximize the number of non-overlapping quests selected from a set of time intervals.

Experimental benchmarking confirmed the theoretical time complexity of:

```text
O(n log n)
```

The algorithm remained efficient even for datasets containing one million quests, demonstrating the practicality of greedy methods for large scheduling problems.

---

## Author

**Desire Roslin Dziele**  
Computer Science Student  
University of Łódź