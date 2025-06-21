/**


Find the subarray [l..r] and a number x such that every element in the subarray is >= x.
Maximize the cost = x * (r - l + 1)


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



void _solve() {
    int n; cin>>n;
    vector<int> arr(n), l(n), r(n); 
    for(int i=0; i<n; i++) cin>>arr[i];
    
    //Nearest element on left
    stack<int> left, right;   
    for(int i=0; i<n; i++){
        while(left.size() && arr[left.top()] >= arr[i]){
            left.pop();
        }
        if(left.size() == 0) l[i] = -1;
        else l[i] = left.top();
        left.push(i);
    }
    
    //Nearest element on right
    for(int i=n-1; i>=0; i--){
        while(right.size() && arr[right.top()] >= arr[i]){
            right.pop();
        }
        if(right.size() == 0) r[i] = n;
        else r[i] = right.top();
        right.push(i);
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, arr[i] * (r[i] - l[i] - 1));
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
