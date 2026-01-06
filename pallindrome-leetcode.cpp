class Solution {
public:
    bool isPalindrome(int x) {
        int copy = x;
        int rev = 0; int last = 0;

        while(copy >0)
        {
            last = copy%10;
            copy = copy/10;

            if(rev > INT_MAX/10 || rev < INT_MIN/10)
            return false;

            rev = (rev*10)+last;
        }

        if(rev==x){return true;}
        else return false;
    }
};
