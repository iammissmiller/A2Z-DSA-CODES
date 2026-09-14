class Solution {
public:
    long long minOperations(vector<int>& nums) {
        const int M = 1000000000;

        vector<int> P[2];

        // Generate all palindromes
        for (int v = 1; v < 100000; v++) {
            string s = to_string(v);

            // Odd length palindrome
            string s1 = s.substr(0, s.size() - 1);
            reverse(s1.begin(), s1.end());
            s1 = s.substr(0, s.size() - 1) + s;

            // Let's construct them directly
            string a = s;
            string b = s;

            // Odd length
            string r1 = s.substr(0, s.size() - 1);
            reverse(r1.begin(), r1.end());
            long long p1 = stoll(s + r1);

            // Even length
            string r2 = s;
            reverse(r2.begin(), r2.end());
            long long p2 = stoll(s + r2);

            if (p1 < M)
                P[p1 & 1].push_back(p1);

            if (p2 < M)
                P[p2 & 1].push_back(p2);
        }

        sort(P[0].begin(), P[0].end());
        sort(P[1].begin(), P[1].end());

        long long ans = 0;

        for (int a : nums) {
            vector<int>& p = P[a & 1];

            int i = lower_bound(p.begin(), p.end(), a) - p.begin();

            if (i == p.size())
                i--;

            long long best = abs((long long)a - p[i]);

            if (i > 0)
                best = min(best, abs((long long)a - p[i - 1]));

            ans += best / 2;
        }

        return ans;
    }
};
