//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
    static long mergeAndCount(int[] arr, int l, int m, int r) {
        int[] left = Arrays.copyOfRange(arr, l, m + 1);
        int[] right = Arrays.copyOfRange(arr, m + 1, r + 1);

        int i = 0, j = 0, k = l;
        long swaps = 0;

        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                swaps += (left.length - i); // all remaining left[] are > right[j]
            }
        }

        while (i < left.length) arr[k++] = left[i++];
        while (j < right.length) arr[k++] = right[j++];

        return swaps;
    }

    static long mergeSortAndCount(int[] arr, int l, int r) {
        long count = 0;
        if (l < r) {
            int m = (l + r) / 2;

            count += mergeSortAndCount(arr, l, m);
            count += mergeSortAndCount(arr, m + 1, r);
            count += mergeAndCount(arr, l, m, r);
        }
        return count;
    }

    static int inversionCount(int arr[]) {
        
        int n = arr.length;
        int ans = (int)mergeSortAndCount(arr, 0, n-1);
        return ans;
    }
}
