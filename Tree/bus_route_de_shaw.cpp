/**

Given a tree with $N$ nodes, each colored either red or blue, find the total number of valid extra edges. 
An edge $(i, j)$ is valid if it forms a cycle of length ≥ 3 and all nodes in the cycle are the same color.


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

long long mod_pow(long long x, long long y, int mod) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invFact[MAXN-1] = mod_pow(fact[MAXN-1], MOD-2, MOD);  
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
}


long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

//nCr - end

//cntrl + B

const ll mod = 998244353;
vector<ll> prime;
vector<ll> sumPrime;
set<ll> checkPrime;
ll Nmax = 2e6 + 1;
int isPrime[2000005];

void sieve(){
  sumPrime.assign(Nmax,0);
  memset(isPrime, 1, sizeof isPrime);
  isPrime[0] = isPrime[1] = 0;
  for(ll i=2; i * i < Nmax; i++){
    if(isPrime[i] == 0) continue;
    for(ll j=i*i; j < Nmax; j += i){
      isPrime[j] = 0;
    }
  }
  
  for(int i=1; i<Nmax; i++){
    sumPrime[i] = sumPrime[i-1];
    if(isPrime[i]) sumPrime[i] += i;
  }
  
  for(ll i=2; i<Nmax; i++){
    if(isPrime[i]) prime.push_back(i);
  }
  for(ll x : prime){
    checkPrime.insert(x);
  }
  
}

ll power(ll n, ll p){
  if(p == 1) return n;
  if(p == 0) return 1;
  ll half = power(n, p/2);
  ll full = (half%mod * half%mod)%mod;
  if(p&1) full = (full%mod * n%mod)%mod;
  return full;
}

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}


void dfs(int src, vector<bool>& vis, int color, vector<int> adj[], int& count, int arr[]){
    if(arr[src] == color) count++;
    vis[src] = true;
    for(int nbr : adj[src]){
        if(vis[nbr] == false && arr[nbr] == color){
            dfs(nbr, vis, color, adj, count, arr);
        }
    }
}

void _solve() {
    int n; cin>>n;
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int x; cin>>x;
        int y; cin>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int arr[n+1];
    for(int i=1; i<=n; i++) cin>>arr[i];
    vector<bool> vis(n+1, false);
    int ans = 0;
    for(int i=1; i<=n; i++){
        int count = 0;
        dfs(i, vis, arr[i], adj, count, arr);
        if(count >= 2)
            ans += (((count-2) * (count - 1))/2);
    }
    cout<<ans<<"\n";
}





int main(){
  
  //sieve();
  
  int t = 1; //cin>>t;
  while(t--){
    _solve();
  }
  
}

