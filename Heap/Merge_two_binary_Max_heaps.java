//Merge two binary Max heaps
//https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
class Solution {
    
    public void heapify(int[] arr, int n, int idx){
        if(idx >= n) return;
        int l = 2 * idx + 1;
        int r = 2 * idx + 2;
        
        int maxI = idx;
        if(l < n && arr[l] > arr[idx]) maxI = l;
        if(r < n && arr[r] > arr[maxI]) maxI = r;
        
        if(maxI != idx){
            int t = arr[maxI];
            arr[maxI] = arr[idx];
            arr[idx] = t;
            heapify(arr, n, maxI);
        }
        
    }
    public int[] mergeHeaps(int[] a, int[] b, int n, int m) {
        
        
        int[] c = new int[n+m];
        for(int i=0; i<n; i++) c[i] = a[i];
        for(int i=0; i<m; i++) c[i+n] = b[i];
        
        int N = n + m;
        
        // for(int i=N-1; i>=0; i--){
        //     heapify(c, N, i);
        // }
       for(int i=(N/2)-1; i>=0; i--){   // ✅ optimization: start from last non-leaf node
            heapify(c, N, i);
        }
        
        return c;
    }
}
