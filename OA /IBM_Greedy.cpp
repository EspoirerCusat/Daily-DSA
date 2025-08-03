
/** 

Given an array of size N; and a target -> find the minimum number of operations needed to make all elements of array equal to target -> there are multiple
target in order of Q

**/

#include<bits/stdc++.h>
using namespace std;

void _solve() {
    int n; cin>>n;
    vector<int> arr(n); for(int i=0; i<n; i++) cin>>arr[i];
    int q; cin>>q;
    vector<int> qr(q); for(int i=0; i<q; i++) cin>>qr[i];
    sort(arr.begin(), arr.end());
    vector<int> sum(n);
    sum[0] = arr[0];
    for(int i=1; i<n; i++) sum[i] = sum[i-1] + arr[i];
    for(int i=0; i<q; i++){
        int k = qr[i];
        int idx = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
        int cnt1 = idx;
        int cnt2 = n - idx;
        int sum1 = sum[idx-1];
        int sum2 = sum.back() - sum1;
        int ans = k * (cnt1 - cnt2) + sum2 - sum1;
        cout<<ans<<"\n";
    }
}


int main(){
  
  
  int t = 1; //cin>>t;
  while(t--){
    _solve();
  }
  
}

