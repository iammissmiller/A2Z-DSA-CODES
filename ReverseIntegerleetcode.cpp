//Reverse Integer leetcode

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int last = x % 10;
            x /= 10;

            // Check overflow BEFORE updating rev
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
                return 0;

            rev = rev * 10 + last;
        }

        return rev;
    }
};
