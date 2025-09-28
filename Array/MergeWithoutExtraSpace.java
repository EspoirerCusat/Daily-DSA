class Solution {
    public void mergeArrays(int a[], int b[]) {
       
       int n = a.length;
       int m = b.length;
       int l,r; l = n-1; r = 0;
       while(l >= 0 && r < m){
           if(a[l] > b[r]){
               //swap
               int t = a[l]; a[l] = b[r]; b[r] = t;
               l--; r++;
           }else{
               break;
           }
       }
       Arrays.sort(a);
       Arrays.sort(b);
    }
}

//Gap Method...


class Solution {
    public void mergeArrays(int a[], int b[]) {
       
       int n = a.length;
       int m = b.length;
       int len = n + m;
       //Gap method..
       int gap = (len + 1) / 2;
       while(gap > 0){
           int l = 0;
           int r = gap;
           while(r < len){
               if(l < n && r >= n){
                   if(a[l] > b[r-n]){
                       int t = a[l]; 
                        a[l] = b[r-n];
                        b[r-n] = t; 
                   }
                   
               }else if(l >= n){
                   if(b[l-n] > b[r-n]){
                        int t = b[l-n];
                        b[l-n] = b[r-n];
                        b[r-n] = t;
                   }
               }else{
                   if(a[l] > a[r]){
                        int t = a[l];
                        a[l] = a[r];
                        a[r] = t;
                   }
               }
               l++; r++;
           }
           if(gap <= 1) break;
           gap = (gap + 1) / 2;
       }
    }
}
