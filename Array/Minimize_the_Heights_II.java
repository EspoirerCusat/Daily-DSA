//Minimize_the_Heights_II.java
//https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
class Solution {
    public int getMinDiff(int[] arr, int k) {
        Arrays.sort(arr);
        int n = arr.length;
        int ans = arr[n-1] - arr[0];
        int smaller = arr[0] + k;
        int larger = arr[n-1] - k;
        
        for(int i=0; i<n-1; i++){
            int min = Math.min(smaller, arr[i+1] - k);
            int max = Math.max(larger, arr[i] + k);
            if(min < 0) continue;
            ans = Math.min(ans, max - min);
        }
        return ans;
    }
}
