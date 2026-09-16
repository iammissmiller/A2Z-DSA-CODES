class Solution {
    using ll = long long;

    static constexpr ll INF = (1LL << 60);
    static constexpr ll NEG = -(1LL << 60);

    struct SegTree {
        int n;

        vector<ll> mx, mx2;
        vector<int> cnt;

        SegTree(int n) : n(n) {
            mx.assign(4 * n, 0);
            mx2.assign(4 * n, NEG);
            cnt.assign(4 * n, 0);
        }

        void pull(int p) {
            int l = p << 1;
            int r = l | 1;

            if (mx[l] == mx[r]) {
                mx[p] = mx[l];
                cnt[p] = cnt[l] + cnt[r];
                mx2[p] = max(mx2[l], mx2[r]);
            }
            else if (mx[l] > mx[r]) {
                mx[p] = mx[l];
                cnt[p] = cnt[l];
                mx2[p] = max(mx2[l], mx[r]);
            }
            else {
                mx[p] = mx[r];
                cnt[p] = cnt[r];
                mx2[p] = max(mx[l], mx2[r]);
            }
        }

        void applyChmin(int p, ll x) {
            if (mx[p] <= x) return;
            mx[p] = x;
        }

        void push(int p) {
            applyChmin(p << 1, mx[p]);
            applyChmin(p << 1 | 1, mx[p]);
        }

        // Set one position to INF (activate a new index).
        void activate(int p, int l, int r, int pos) {
            if (l == r) {
                mx[p] = INF;
                mx2[p] = NEG;
                cnt[p] = 1;
                return;
            }

            push(p);

            int mid = (l + r) >> 1;

            if (pos <= mid)
                activate(p << 1, l, mid, pos);
            else
                activate(p << 1 | 1, mid + 1, r, pos);

            pull(p);
        }

        void activate(int pos) {
            activate(1, 0, n - 1, pos);
        }

        // range chmin: a[i] = min(a[i], x)
        void chmin(int p, int l, int r,
                   int ql, int qr, ll x) {

            if (qr < l || r < ql || mx[p] <= x)
                return;

            if (ql <= l && r <= qr && mx2[p] < x) {
                applyChmin(p, x);
                return;
            }

            push(p);

            int mid = (l + r) >> 1;

            chmin(p << 1, l, mid, ql, qr, x);
            chmin(p << 1 | 1, mid + 1, r, ql, qr, x);

            pull(p);
        }

        void chmin(int l, int r, ll x) {
            if (l <= r)
                chmin(1, 0, n - 1, l, r, x);
        }

        // Count values >= x in [ql, qr].
        int countGE(int p, int l, int r,
                    int ql, int qr, ll x) {

            if (qr < l || r < ql || mx[p] < x)
                return 0;

            // Every maximum is >= x and everything else is < x.
            if (ql <= l && r <= qr && mx2[p] < x)
                return cnt[p];

            if (l == r)
                return mx[p] >= x;

            push(p);

            int mid = (l + r) >> 1;

            return countGE(p << 1, l, mid, ql, qr, x)
                 + countGE(p << 1 | 1, mid + 1, r,
                           ql, qr, x);
        }

        int countGE(int l, int r, ll x) {
            if (l > r) return 0;
            return countGE(1, 0, n - 1, l, r, x);
        }
    };

public:
    long long shadowPairs(vector<int>& nums) {

        int n = nums.size();

        // Give every occurrence a position in value-sorted order.
        vector<int> order(n);

        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(),
             [&](int a, int b) {
                 if (nums[a] != nums[b])
                     return nums[a] < nums[b];

                 return a < b;
             });

        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[order[i]] = i;

        // Number of elements whose value is < x.
        vector<int> sortedValues(n);

        for (int i = 0; i < n; i++)
            sortedValues[i] = nums[order[i]];

        SegTree seg(n);

        long long ans = 0;

        for (int j = 0; j < n; j++) {

            int x = nums[j];

            // All positions with value < x.
            int p = lower_bound(
                sortedValues.begin(),
                sortedValues.end(),
                x
            ) - sortedValues.begin();

            /*
                For every previous i:

                    nums[i] < x
                    limit[i] >= x

                => (i,j) is a shadow pair.
            */
            if (p > 0) {
                ans += seg.countGE(0, p - 1, x);

                // x now becomes the smallest blocker
                // for every nums[i] < x.
                seg.chmin(0, p - 1, x);
            }

            // Current index becomes a new candidate
            // with no blocker yet.
            seg.activate(pos[j]);
        }

        return ans;
    }
};
