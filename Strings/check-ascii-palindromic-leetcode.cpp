class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";
        for(char c : s)
            {
                int x = c;
            
                for(int i = 7 ; i >= 0 ; i--)
                    {
                        if(x & (1 << i))
                            binary += '1';
                        else
                            binary += '0';
                    }
                
            }

        
        string rev = binary;
        reverse(rev.begin(),rev.end());

        return binary == rev ;
    }
};
