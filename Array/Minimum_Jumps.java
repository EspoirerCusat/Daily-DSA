
//Minimum Jumps
//https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1


class Solution {
    public int minJumps(int[] arr) {
        
        int n = arr.length;
        int steps = arr[0];
        if(steps == 0) return -1;
        int maxJump = 0;
        int jump = 1;
        
        for(int i=1; i<n; i++){
            if(i == n-1) return jump;
            maxJump = Math.max(maxJump, i + arr[i]);
            if(steps == i){
                jump++;
                steps = maxJump;
                if(steps <= i) return -1;
            }
        }
        return -1;
    }
}
