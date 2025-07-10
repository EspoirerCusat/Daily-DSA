/**

Find the closest pair from two arrays
https://www.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1

**/

class Solution {
    // Complete this function
    public List<int> printClosest(int[] arr, int[] brr, int n, int m, int x) {
        // code here
        int i = 0; 
        int j = m-1;
        int l,r; l = r = 0;
        int diff = int.MaxValue;
        while(i < n && j >= 0){
            if(Math.Abs(arr[i] + brr[j] - x) < diff){
                l = i; r = j;
                diff = Math.Abs(arr[i] + brr[j] - x);
            }
            if((arr[i] + brr[j]) > x) j--;
            else i++;
        }
        return new List<int> {arr[l], brr[r]};
    }
}
