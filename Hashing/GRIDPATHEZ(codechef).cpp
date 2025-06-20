#include <bits/stdc++.h>
using namespace std;
#define INF 1e10
#define ll long long


void solve(){
    int n; cin>>n;
    int q; cin>>q;
    
    string row1; cin>>row1;
    string row2; cin>>row2;
    
    set<ll> st1;
    for(int i=0; i<n; i++){
        if(row1[i] == '1') st1.insert(i);
    }
    set<ll, greater<ll>> st2;
    for(int i=0; i<n; i++){
        if(row2[i] == '1') st2.insert(i);
    }
    
    vector<vector<ll>> dp(2, vector<ll>(n, 0));
    
    for(int i=0; i<n; i++){
        if(i != 0) dp[0][i] = dp[0][i-1];
        if(st1.size() > 0){
            ll x = *st1.begin();
            st1.erase(st1.begin());
            dp[0][i] += x - i;
        }else{
            dp[0][i] = INF;
        }
    }
    
    for(int i=n-1; i>=0; i--){
        if(i != n-1) dp[1][i] += dp[1][i+1];
        if(st2.size() > 0){
            ll x = *st2.begin();
            st2.erase(st2.begin());
            dp[1][i] += i - x;
        }else{
            dp[1][i] = INF;
        }
    }
    
    ll ans = INF;
    for(int i=0; i<n; i++) ans = min(ans, dp[0][i] + dp[1][i]);
    if(ans >= INF) cout<<"-1\n";
    else cout<<ans<<"\n";
    
    
}



int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
}
