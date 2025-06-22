
/**

https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/

**/


class Solution {
public:
    int f(vector<int>& arr){
        int n = arr.size();
        int res = 0;
        //Try to fit at 0, 2, 4, 6....
        for(int i=0; i<n; i++){
            res += abs(2 * i - arr[i]);
        }

        return res;
    }
    int minSwaps(vector<int>& nums) {
        vector<int> odd,even;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]&1) odd.push_back(i);
            else even.push_back(i);
        }
        int odd_count = odd.size();
        int even_count = even.size();

        if(abs(odd_count - even_count) > 1){
            return -1;
        }

        int ans = INT_MAX;

        if(odd_count >= even_count){
            ans = min(ans, f(odd));
        }
        if(even_count >= odd_count){
            ans = min(ans, f(even));
        }
        return ans;
    }
};
