
//https://www.geeksforgeeks.org/problems/maximum-difference-between-pair-in-a-matrix/1


class Solution {
    public static int findMaxValue(int n, int[][] mat) {
        int[][] max = new int[n][n];
        
        // Fill last element
        max[n-1][n-1] = mat[n-1][n-1];
        
        // Fill last row
        for (int j = n-2; j >= 0; j--) {
            max[n-1][j] = Math.max(mat[n-1][j], max[n-1][j+1]);
        }
        
        // Fill last column
        for (int i = n-2; i >= 0; i--) {
            max[i][n-1] = Math.max(mat[i][n-1], max[i+1][n-1]);
        }
        
        int ans = Integer.MIN_VALUE;
        
        // Fill rest
        for (int i = n-2; i >= 0; i--) {
            for (int j = n-2; j >= 0; j--) {
                // candidate difference
                ans = Math.max(ans, max[i+1][j+1] - mat[i][j]);
                
                // update max
                max[i][j] = Math.max(mat[i][j],
                                Math.max(max[i+1][j], max[i][j+1]));
            }
        }
        
        return ans;
    }
}
