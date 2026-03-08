# Majority Element – I

## Problem

Given an array of size **n**, find the element that appears **more than ⌊n/2⌋ times**.

It is guaranteed that the majority element **exists**.

### Example

```
Input:  [2,2,1,1,1,2,2]
Output: 2
```

Explanation:

```
2 appears 4 times
n = 7
n/2 = 3
4 > 3 → Majority element = 2
```

---

# 1. Brute Force Approach

## Idea

For every element, count how many times it appears.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElementBrute(vector<int>& arr)
{
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int count = 0;

        for(int j = 0; j < n; j++)
        {
            if(arr[j] == arr[i])
                count++;
        }

        if(count > n/2)
            return arr[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2,2,1,1,1,2,2};

    cout << majorityElementBrute(arr);
}
```

### Complexity

Time → **O(n²)**
Space → **O(1)**

---

# 2. Better Approach (HashMap)

## Idea

Use a frequency map to count occurrences.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElementBetter(vector<int>& arr)
{
    unordered_map<int,int> mp;
    int n = arr.size();

    for(int x : arr)
    {
        mp[x]++;

        if(mp[x] > n/2)
            return x;
    }

    return -1;
}

int main()
{
    vector<int> arr = {2,2,1,1,1,2,2};

    cout << majorityElementBetter(arr);
}
```

### Complexity

Time → **O(n)**
Space → **O(n)**

---

# 3. Optimal Approach (Boyer–Moore Voting Algorithm) ⭐

This is the **most important interview solution**.

## Idea

If an element appears **more than n/2 times**, it will always survive cancellation.

We:

* Increase count if same element
* Decrease count if different element

---

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int majorityElementOptimal(vector<int>& arr)
{
    int count = 0;
    int candidate = 0;

    for(int x : arr)
    {
        if(count == 0)
            candidate = x;

        if(x == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}

int main()
{
    vector<int> arr = {2,2,1,1,1,2,2};

    cout << majorityElementOptimal(arr);
}
```

---

# Complexity (Optimal)

Time → **O(n)**
Space → **O(1)**

---

# Intuition Example

Array:

```
2 2 1 1 1 2 2
```

Cancel pairs:

```
2 2 1 1 1 2 2
↓ ↓
remove pairs of different elements
```

Remaining dominant element → **2**

---

# Interview Pattern Recognition ⭐

If question says:

```
element appears > n/2 times
```

Immediately think:

```
Boyer Moore Voting Algorithm
```

---
