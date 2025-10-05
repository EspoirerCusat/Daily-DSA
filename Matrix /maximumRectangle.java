
//https://www.geeksforgeeks.org/problems/max-rectangle/1

class Solution {
    static int maximumAreaOfHistogram(int arr[]){
        int n = arr.length;
        Stack<Integer> stk = new Stack<>();
        int[] l = new int[n];
        int[] r = new int[n];
        //left -- smallest element in left
        for(int i=0; i<n; i++){
            while(!stk.isEmpty() && arr[stk.peek()] >= arr[i]){
                stk.pop();
            }
            if(stk.isEmpty()) l[i] = -1;
            else l[i] = stk.peek();
            stk.push(i);
        }
        while(!stk.isEmpty()){
            stk.pop();
        }
        //right 
        for(int i=n-1; i>=0; i--){
            while(!stk.isEmpty() && arr[stk.peek()] >= arr[i]){
                stk.pop();
            }
            if(stk.isEmpty()) r[i] = n;
            else r[i] = stk.peek();
            stk.push(i);
        }
        
        //Calculate answer
        int ans = 0;
        for(int i=0; i<n; i++){
            int res = arr[i] * (r[i] - l[i] - 1);
            ans = Math.max(ans, res);
        }
        return ans;
    }
    static int maxArea(int mat[][]) {
        
        int n = mat.length;
        int m = mat[0].length;
        
        int[] pref = new int[m];
        for(int i=0; i<m; i++) pref[i] = 0;
        
        int ans = 0;
        
        for(int i=0; i<n; ++i){
            
            for(int j=0; j<m; j++){
                pref[j] += mat[i][j];
                if(mat[i][j] == 0) pref[j] = 0;
            }
            
            ans = Math.max(ans, maximumAreaOfHistogram(pref));
        }
        
        return ans;
    }
}
