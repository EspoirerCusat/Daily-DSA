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

void Google(){
    //Pre-requisite
    int n; cin>>n;
    int a[n]; for(int i=0; i<n; i++) cin>>a[i];
    int b[n]; for(int i=0; i<n; i++) cin>>b[i];
    map<int,int> aMap, bMap;
    for(int i=0; i<n; i++){
        aMap[a[i]]++;
        bMap[b[i]]++;
    }
    //count (ai, bj) ==> b[j] % a[i] == 0
    int ans = 0;
    for(auto& [_a, cnt] : aMap){
        for(int j=_a; j<MAXN; j += _a){
            if(bMap.count(j) > 0)
                ans += (cnt * bMap[j]);
        }
    }
    cout<<ans<<"\n";
}

const int dx[] = {-1, 0, +1, 0};
const int dy[] = {0, +1, 0, -1};
int dfs(int i, int j, vector<vector<int>>& mat, int& cnt){
    int n = mat.size(); int m = mat[0].size();
    if(i < 0 || j < 0 || i >= n || j >= m) return 0;
    if(mat[i][j] == -1) return 0;
    int sum = mat[i][j];
    mat[i][j] = -1;
    cnt++;
    for(int k=0; k<4; k++){
        int idx = i + dx[k]; 
        int jdx = j + dy[k];
        sum += dfs(idx, jdx, mat, cnt);
    }
    return sum;
}


void MediaDotNet_Easy(){
    int n; cin>>n; int m; cin>>m;
    //Impossible to reach elements
    vector<vector<int>> mat(n, vector<int>(m));
    int pos = 0; int neg = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
            if(mat[i][j] > 0) pos += mat[i][j];
            else neg++;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] > 0){
                int cnt = 0;
                int comp = dfs(i, j, mat, cnt);
                ans += cnt * (pos - comp);
            }
        }
    }

    ans -= neg;
    cout<<ans<<"\n";
    
}

void dfsHard(int i, int j, vector<vector<int>>& mat, map<int,int>& temp){
    int n = mat.size(); int m = mat[0].size();
    if(i < 0 || j < 0 || i >= n || j >= m) return ;
    if(mat[i][j] == -1) return ;
    temp[mat[i][j]]++;
    mat[i][j] = -1;
    for(int k=0; k<4; k++){
        int idx = i + dx[k]; 
        int jdx = j + dy[k];
        dfsHard(idx, jdx, mat, temp);
    }
}

void MediaDotNet_Hard(){
    int n; cin>>n; int m; cin>>m;
    vector<vector<int>> mat(n, vector<int>(m));
    int pos = 0; int neg = 0;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
            if(mat[i][j] < 0) neg++;
            else{
                mp[mat[i][j]]++;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] < 0) continue;
            
            map<int, int> temp;
            dfsHard(i, j, mat, temp);
            
            for(auto& [_a, cnt] : temp){
                mp[_a] -= cnt;
            }
            
            for(auto& [_a, cnt] : temp){
                for(int j=_a; j<MAXN; j+=_a){
                    if(mp.count(j) > 0)
                        ans += cnt * j * mp[j];
                }
            }
            
            for(auto& [_a, cnt] : temp){
                mp[_a] += cnt;
            }
        }
    }
    
    ans -= neg;
    cout<<ans<<"\n";
}




void _solve() {

    // Google();
    //MediaDotNet_Easy();
    MediaDotNet_Hard();
}





int main(){
  
  //sieve();
  
  int t = 1; //cin>>t;
  while(t--){
    _solve();
  }
  
}
