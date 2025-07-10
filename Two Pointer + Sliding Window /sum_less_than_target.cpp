/**

Count Pairs whose sum is less than target
https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1

**/


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        
        sort(arr.begin(), arr.end());
        //2 - Pointer
        int n = arr.size();
        int l = 0; int r = n-1;
        
        int count = 0;
        while(l <= r){
            int sum = arr[l] + arr[r];
            if(sum < target){
                count += r - l;
                l++;
            }else{
                r--;
            }
        }
        return count;
    }
};
