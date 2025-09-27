
//Sort 0s, 1s and 2s
//https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


class Solution {
    public void sort012(int[] arr) {
        // code here
        int low,mid,high;
        low = 0; high = arr.length - 1; mid = 0;
        while(mid <= high){
            if(arr[mid] == 0){
                //swap
                int t = arr[mid];
                arr[mid] = arr[low];
                arr[low] = t;
                low++; mid++;
            }else if(arr[mid] == 1){
                mid++;
            }else{
                int t = arr[mid];
                arr[mid] = arr[high];
                arr[high] = t;
                high--;
            }
        }
    }
}
