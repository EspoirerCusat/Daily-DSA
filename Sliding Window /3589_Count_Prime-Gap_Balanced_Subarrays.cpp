/**
  
https://leetcode.com/problems/count-prime-gap-balanced-subarrays/

**/
class Solution {
public:
    int isPrime[100000];
    int N = 100000;
    void sieve(){
        memset(isPrime, 1, sizeof isPrime);
        isPrime[0] = isPrime[1] = 0;
        for(long long i = 2; i < N; i++){
            if(isPrime[i] == 0) continue;
            for(long long j = i * i; j < N; j += i){
                isPrime[j] = 0; 
            }
        }
    }
    Solution(){
        sieve();
    }

    int primeSubarray(vector<int>& nums, int k) {
        //maintain last prime (last - l + 1) answer hoga
        int l,r,last; l = 0; r = 0; last = -1;
        int N = nums.size();
        //max_prime - min_prime <= k
        multiset<int> ms;
        int ans = 0; int curr = -1;
        while(r < N){
            if(isPrime[nums[r]]){
                ms.insert(nums[r]);
                last = curr; 
                curr = r;
            }

            while(ms.size() > 0 && *ms.rbegin() - *ms.begin() > k){
                if(isPrime[nums[l]]){
                    ms.erase(ms.find(nums[l]));
                }
                l++;
            }
            
            if(ms.size() >= 2 && *ms.rbegin() - *ms.begin() <= k){
                ans += (last - l + 1);
            }
            r++;
        }
        return ans;
    }
};
