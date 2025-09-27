

//1673. Find the Most Competitive Subsequence
//https://leetcode.com/problems/find-the-most-competitive-subsequence/description/

class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        Stack<Integer> stk = new Stack<>();
        int n = nums.length;
        int extra = n - k; //need to remove
        int[] ans = new int[k];
        for(int num : nums){
            while(!stk.isEmpty() && extra > 0 && stk.peek() > num){
                stk.pop();
                extra--;
            }
            stk.push(num);
        }
        int i = 0;
        for(Integer x : stk){
            ans[i] = x;
            i++;
            if(i >= k) break;
        }
        return ans;
    }
}
