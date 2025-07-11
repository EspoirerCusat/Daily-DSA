

// First negative in every window of size k
//https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1


class Solution {
    static List<Integer> firstNegInt(int arr[], int k) {
       
       List<Integer> list = new ArrayList<>();
       
       int n = arr.length;
    // Space : O(n)
    //   int i = 0; int j = 0;
    //   Queue<Integer> q = new LinkedList<Integer>();
    //   while(j < n){
    //       if(arr[j] < 0){
    //           q.add(arr[j]);
    //       }
    //       if(j - i + 1 == k){
    //             if(q.size() != 0)
    //                 list.add(q.peek());
    //             else list.add(0);
    //             if(arr[i] < 0)
    //                 q.remove();
    //             i++;
    //       }
    //       j++;
    //   }
    
    //Space : O(1)
        int negIndex = 0;
        for(int i=k-1; i<n; i++){
            while(negIndex < i && (arr[negIndex] >= 0  || negIndex < i - k + 1)){
                negIndex++;
            }
            if(negIndex < n && arr[negIndex] < 0) list.add(arr[negIndex]);
            else list.add(0);
        }
       return list;
    }
}
