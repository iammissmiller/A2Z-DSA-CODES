# Merge Overlapping Intervals

## Problem

Given a list of intervals, merge all **overlapping intervals** and return the result.

---

### Example

```text
Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]
```

Explanation:

* `[1,3]` and `[2,6]` overlap → merged to `[1,6]`

---

# 1. Brute Force Approach

## Idea

For each interval:

* Compare with others
* Merge if overlapping

Not efficient, but for understanding.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeBrute(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for(int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        for(int j = i+1; j < n; j++)
        {
            if(intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else break;
        }

        ans.push_back({start, end});
    }

    return ans;
}
```

### Complexity

Time → **O(n²)**
Space → **O(n)**

---

# 2. Optimal Approach (Sorting + Greedy) ⭐

## Idea

1. Sort intervals based on start time
2. Compare with last interval in result
3. Merge if overlapping

---

## Overlap Condition

```text
current.start <= last.end
```

---

# Optimal C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for(int i = 0; i < n; i++)
    {
        if(ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> intervals = {
        {1,3},{2,6},{8,10},{15,18}
    };

    vector<vector<int>> ans = mergeIntervals(intervals);

    for(auto v : ans)
    {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
}
```

---

# Complexity

Time → **O(n log n)** (due to sorting)
Space → **O(n)**

---

# Dry Run

Sorted:

```text
[1,3] [2,6] [8,10] [15,18]
```

Step-by-step:

```
[1,3] + [2,6] → merge → [1,6]
[8,10] → no overlap
[15,18] → no overlap
```

---

# Key Interview Insight ⭐

If interviewer says:

```text
Merge overlapping intervals
```

Think:

```text
Sort + Greedy
```

---

# Common Mistakes

1. Not sorting first ❌
2. Wrong overlap condition ❌
3. Not updating last interval properly ❌

---

# Pattern Recognition

| Problem Type    | Approach       |
| --------------- | -------------- |
| Merge intervals | Sort + Greedy  |
| Meeting rooms   | Sort + compare |
| Insert interval | Same logic     |

---
