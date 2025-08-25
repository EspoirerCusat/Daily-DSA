
/***

Find the minimum cost where you can take max k jumps.
  
***/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fo(i, start, end) for (ll i = start; i <= end; i++)
#define pfo(i, end, start) for (ll i = end; i >= start; i--)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sortall(v) sort(all(v))
#define sumv(v) accumulate(all(v), 0LL)

int main(){
    
    ll n;
    cin>>n;ll vl[n+1]={0};ll k;cin>>k; 
    fo(i,1,n){
        cin>>vl[i];
    }
	ll dp[n+1];
	dp[0] = 0 ; 
	fo(i,1,n){ dp[i] = 1e18; 
	}
	multiset <ll> d1; d1.insert(dp[0]);
	fo(i,1,n){ll l = 0 ; 
	    
	    dp[i] = *(d1.begin()) + vl[i]; 
	    
	    d1.insert(dp[i]);
	    if(i-k>=0){
	        d1.erase(d1.find(dp[i-k]));
	    }
	}
	
	cout<<dp[n];
	return 0;
}





