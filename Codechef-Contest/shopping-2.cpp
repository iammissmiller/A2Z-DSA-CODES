#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	if(cin>>t)
	{
	    while(t--)
	    {
	        int n;
	        long long d;
	        cin >> n >> d;
	        
	        vector<long long> a(n),b(n);
	        
	        long long suma = 0 , sumb = 0 , summin = 0;
	        
	        for(int i = 0 ; i < n ; ++i)
	        {
	            cin >> a[i];
	            suma += a[i];
	        }
	        
	        for(int i = 0; i < n ; ++i)
	        {
	            cin >> b[i];
	            sumb += b[i];
	            summin += min(a[i],b[i]);
	        }
	        
	        long long ans = min({d+suma, d + sumb , 2*d + summin});
	        cout << ans << "\n";
	    }
	}
	
	return 0;

}
