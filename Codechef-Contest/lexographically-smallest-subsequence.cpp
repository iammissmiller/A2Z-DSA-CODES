#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	if(cin >> t)
	{
	    while(t--)
	    {
	        string s; 
	        int k ;
	        cin >> s >> k;
	        
	        int n = s.length();
	        
	        string res = "";
	        
	        for(int i = 0 ; i < n ; i++)
	        {
	            int remaining = n-i;
	            
	            while(!res.empty()&&res.back()>s[i]&&(res.length()+remaining > k))
	            {
	                res.pop_back();
	            }
	            if(res.length()<k)
	            {
	                res.push_back(s[i]);
	            }
	        }
	        
	        cout << res << "\n";
	    }
	}
	
	return 0;

}
