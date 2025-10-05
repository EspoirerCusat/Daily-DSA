
//https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

class Solution {
    
    int upper_bound(int[][] mat, int tar){
        int n = mat.length;
        int cnt = 0;
        int r = 0;
        int c = n-1;
        while(r < n && c >= 0){
            if(mat[r][c] <= tar){
                cnt += c + 1;
                r++;
            }else{
                c--;
            }
        }
        return cnt;
    }
    public int kthSmallest(int[][] mat, int k) {
       int n = mat.length;
       int s = mat[0][0];
       int e = mat[n-1][n-1];
       int ans = 0;
       
       while(s <= e){
           int mid = (s + e) >> 1;
           int cnt = upper_bound(mat, mid);
           if(cnt < k){
               s = mid + 1;
           }else{
               ans = mid;
               e = mid - 1;
           }
       }
       return ans;
    }
}
