
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int maxFactor = 0;
        for (auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
        }

        // Count frequency of factors
        vector<int> freq(maxFactor + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        // Count all divisible factors
        vector<int> count = freq;

        for (int f = 1; f <= maxFactor; f++) {
            for (int j = 2 * f; j <= maxFactor; j += f) {
                count[f] += freq[j];
            }
        }

        // Sort by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long minPrice = items[0][1];
        long long ans = 0;
        long long remaining = budget;

        // Greedy: purchase items with free-item benefits
        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (price > 2 * minPrice) {
                break;
            }

            long long gain = count[factor] - 1;

            long long take = min(gain, remaining / price);

            ans += 2 * take;
            remaining -= take * price;
        }

        // Spend remaining budget on cheapest item
        ans += remaining / minPrice;

        return (int)ans;
    }
};
