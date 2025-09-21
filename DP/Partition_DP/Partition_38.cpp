#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18

//nCr - start

const int MOD = 1e9+7; 
const int MAXN = 1e5+5; 

const ll _MOD =  998244353;
void _solve_easy(){
    int n; cin>>n; int m; cin>>m;
    vector<int> arr(n+1), dp(n+1,0);
    for(int i=1; i<=n; i++) cin>>arr[i];
    dp[0] = 1;
    
    for(int i=1; i<=n; i++){
        int currSum = 0;
        for(int j=i; j>0; j--){
            currSum += arr[j];
            if(currSum <= m){
                dp[i] += dp[j-1];
            }else{
                break;
            }
        }
    }
    
    cout<<dp[n]<<"\n";
    
}


void _solve(){
    //-> Given an array of size ‘N’; 
    // find the number of ways to partition it such that the sum of each part is <=M ; 
    // but you should only make k partitions!
    int n; cin>>n;
    int m; cin>>m;
    int k; cin>>k;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin>>arr[i];
    vector<vector<int>> dp(n+1, vector<int>(k+1, -MAXN));
    dp[0][0] = dp[1][1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=1; j<=k; j++){
            int currSum = 0;
            int cnt = 0;
            for(int x=j; x>=1; x--){
                currSum += arr[x];
                if(currSum > m) break;
                if(dp[x-1][j-1] > 0)
                    cnt += dp[x-1][j-1];
            }
            if(cnt > 0){
                dp[i][j] = cnt;
            }
        }
    }
    cout<<dp[n][k]<<"\n";
}



int main(){
  
  //sieve();
  
  int t = 1; //cin>>t;
  while(t--){
    _solve();
  }
  
}
