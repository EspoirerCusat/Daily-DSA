

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
    //Rubrik
    int n; cin>>n;
    int arr[n]; for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> res(n+5);
    vector<int> temp;
    int len = 0;
    
    //Base case
    int g = 0;
    for(int i=0; i<n; i++){
        g = gcd(g, arr[i]);
    }
    if(g != 1){
        for(int k=2; k<=n; k++){
            cout << n / (k - 1) << " ";
        }
        return;
    }
    
    //l .. r
    int r = n-1;
    g = arr[0];
    while(gcd(g, arr[r]) != 1){
        r--;
    }
    int l = 1;
    g = arr[0];
    while(gcd(g, arr[l]) != 1){
        l++;
    }
    
    int L = l - 1 + n - r - 1;
    
    if(L > 1)
        temp.push_back(L);
    
    len = 0; g = 0;
    for(int i = l; i <= r; i++){
        if(gcd(g, arr[i]) != 1){
            g = gcd(g, arr[i]);
            len++;
        }else{
            if(len > 1)
                temp.push_back(len-1);
            g = arr[i];
            len = 1;
        }
    }
    
    for(int t : temp){
        for(int k = 2; k <= n; k++){
            res[k] += t / (k - 1);
        }
    }
    
    for(int k = 2; k <= n; k++){
        cout<<res[k]<<" ";
    }
    
}

int main(){
  
  sieve();
  
  int t = 1; //cin>>t;
  while(t--){
    _solve();
  }
  
}





// [3 , 4 , 5 , 6 , 9]
// O/P - 2 
