class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        auto temoravlin = intervals;

        sort(temoravlin.begin(), temoravlin.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        long long ans = 0;

        for (auto& interval : temoravlin) {
            int start = interval[0];

            while (!pq.empty() && pq.top() < start)
                pq.pop();

            ans += pq.size();

            pq.push(interval[1]);
        }

        return ans;
    }
};
