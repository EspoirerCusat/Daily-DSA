//https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int i=0; int j=0;
        int n = matrix.length;
        int m = matrix[0].length;
        j = m-1;
        while(i < n && j >= 0){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target) j--;
            else {
                i++;
            }
        }
        return false;
    }
}

//log(n)

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int s = 0;
        int e = matrix.length-1;
        int idx = e;
        while(s <= e){
            int mid = (s + e) / 2;
            if(matrix[mid][0] <= target){
                idx = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        int idxE = Arrays.binarySearch(matrix[idx], target);
        return idxE < 0 ? false : true;
    }
}
