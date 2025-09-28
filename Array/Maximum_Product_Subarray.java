//https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1


class Solution {
    int maxProduct(int[] arr) {
        
        int mn = 1; int mx = 1;
        int ans = Integer.MIN_VALUE;
        for(int x : arr){
            int tmn = mn; int tmx = mx;
            mn = Math.min(x, Math.min(tmn * x, tmx * x));
            mx = Math.max(x, Math.max(tmn * x, tmx * x));
            ans = Math.max(ans, Math.max(mn, mx));
        }
        return ans;
    }
}
