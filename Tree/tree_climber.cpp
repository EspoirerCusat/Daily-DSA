
/** 

count how many ancestors i have a[i]*a[j] as a perfect square.

**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18

//nCr - start

const int MOD = 1e9+7; 
const int MAXN = 1e5+5; 

const ll _MOD =  998244353;

vector<long long> fact(MAXN), invFact(MAXN);


vector<ll> spf(MAXN + 1); // spf[i] will store the smallest prime factor of i
 
void computeSPF() {
    // Initialize spf for every number to itself
    for (ll i = 2; i <= MAXN; i++) {
        spf[i] = i;
    }
 
    // Start the sieve process
    for (ll i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) { // Check if i is prime
            for (ll j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) { // Update spf[j] to the smallest prime factor
                    spf[j] = i;
                }
            }
        }
    }
}
int oddFact(int x){
    int k = 1;
    
    map<int,int> fact; //(factor, count)
    while(x != 1){
        fact[spf[x]]++;
        x /= spf[x];
    }
    for(auto& itr : fact){
        if(itr.second&1){
            k *= itr.first;
        }
    }
    
    return k;
}

void dfs(int src, int par, vector<int> adj[], map<int,int>& mp, int& count, vector<int>& value){
    count += mp[value[src]];
    mp[value[src]]++;
    
    for(int nbr : adj[src]){
        if(nbr != par){
            dfs(nbr, src, adj, mp, count, value);
        }
    }
    mp[value[src]]--;
}

void _solve() {
    
    int n; cin>>n;
    int arr[n]; for(int i=0; i<n; i++) cin>>arr[i];
    
    //tree
    vector<int> adj[n];
    for(int i=0; i<n-1; i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    //(x * y) ==> perfect square 
    //Find K --> odd powered elements
    computeSPF();
    vector<int> value(n);
    for(int i=0; i<n; i++){
        value[i] = oddFact(arr[i]);
        //cout<<value[i]<<" ";
    }
    
    //dfs kr lo
    map<int,int> mp;
    int count = 0;
    dfs(0, -1, adj, mp, count, value);
    
    cout<<count<<"\n";
}





int main(){
  
  //sieve();
  
  int t = 1; //cin>>t;
  while(t--){
    _solve();
  }
  
}
