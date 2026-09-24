class Solution {
public:

    pair<int, int> expand(string &s, int left, int right) {

        while (left >= 0 && right < s.size() &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - left - 1};
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.size(); i++) {

            auto [start1, len1] = expand(s, i, i);

            auto [start2, len2] = expand(s, i, i + 1);

            if (len1 > maxLen) {
                start = start1;
                maxLen = len1;
            }

            if (len2 > maxLen) {
                start = start2;
                maxLen = len2;
            }
        }

        return s.substr(start, maxLen);
    }
};
