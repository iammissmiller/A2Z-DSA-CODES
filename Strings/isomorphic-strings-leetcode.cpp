class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int mapst[256] = {0};
       int mapts[256] = {0};

       for(int i = 0 ; i < s.size() ; i++)
       {
        if(mapst[s[i]] != mapts[t[i]] )
        {
            return false;
        }

        mapst[s[i]] = i + 1;
        mapts[t[i]] = i + 1;
       }  
       return true;
    }
};
