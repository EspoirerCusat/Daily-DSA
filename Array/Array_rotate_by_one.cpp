
/**
Rotate Array by One
https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
**/
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0; int j = n-1;
        
        while(i != j){
            swap(arr[i], arr[j]);
            i++;
        }
    }
};
