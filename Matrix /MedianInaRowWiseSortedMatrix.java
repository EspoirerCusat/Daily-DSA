
//https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
    public int median(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int pivot = (n * m + 1) >> 1; // median position

        int mn = Integer.MAX_VALUE;
        int mx = Integer.MIN_VALUE;

        // Find global min and max
        for (int i = 0; i < n; i++) {
            mn = Math.min(mn, mat[i][0]);
            mx = Math.max(mx, mat[i][m - 1]);
        }

        while (mn < mx) {
            int mid = mn + (mx - mn) / 2;
            int cnt = 0;

            // Count elements <= mid
            for (int i = 0; i < n; i++) {
                cnt += upper_bound(mat[i], mid);
            }

            if (cnt < pivot) {
                mn = mid + 1;
            } else {
                mx = mid;
            }
        }

        return mn; // or mx, both are same now
    }

    // upper_bound = count of elements <= target
    public int upper_bound(int[] arr, int target) {
        int n = arr.length;
        int s = 0, e = n;
        while (s < e) {
            int mid = (s + e) / 2;
            if (arr[mid] <= target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }
}
