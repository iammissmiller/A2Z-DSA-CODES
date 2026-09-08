class Solution {
    public:
        int countGroups(vector<int>& position, vector<int>& speed, int distance) {
                int n = position.size();

                        vector<long double> times;

                                for (int i = 0; i < n - 1; i++) {
                                            if (speed[i] > speed[i + 1]) {
                                                            long double t =
                                                                                (long double)(position[i + 1] - position[i] - distance)
                                                                                                    / (speed[i] - speed[i + 1]);

                                                                                                                    times.push_back(max((long double)0, t));
                                                                                                                                } else {
                                                                                                                                                times.push_back(1e30);
                                                                                                                                                            }
                                                                                                                                                                    }

                                                                                                                                                                            int groups = 1;

                                                                                                                                                                                    for (int i = 0; i < n - 1; i++) {
                                                                                                                                                                                                if (times[i] == 1e30)
                                                                                                                                                                                                                groups++;
                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                return groups;
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                    };
}
