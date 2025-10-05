
//https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1

class GFG {
    static void rotate(int mat[][]) {
       
       int n = mat.length;
       
       //Transpose
       for(int i=0; i<n; i++){
           for(int j=i; j<n; j++){
               int temp = mat[i][j];
               mat[i][j] = mat[j][i];
               mat[j][i] = temp;
           }
       }
       
       //Reverse columns 
       int l = 0; int r = n-1;
       while(l < r){
           
           for(int j=0; j<n; j++){
               int temp = mat[j][l];
               mat[j][l] = mat[j][r];
               mat[j][r] = temp;
           }
           
           l++; r--;
       }
        
    }
}
