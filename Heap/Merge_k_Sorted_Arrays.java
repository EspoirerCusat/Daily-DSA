

//Merge k Sorted Arrays
//https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

class Solution {
    
    static class data implements Comparable<data> {
        int i, j, val;
        
        data(int val, int i, int j){
            this.val = val;
            this.i = i; 
            this.j = j;
        }
        
        public int compareTo(data d){
            return Integer.compare(this.val, d.val);
        }
    }
    
    
    public static ArrayList<Integer> mergeKArrays(int[][] arr, int K) {
        
        ArrayList<Integer> ans = new ArrayList<>();
        PriorityQueue<data> pq = new PriorityQueue<>();
        
        //Insert 0th element to priority queue
        for(int i=0; i<K; i++){
            pq.add(new data(arr[i][0], i, 0));
        }
        
        while(!pq.isEmpty()){
            data d = pq.poll();
            ans.add(d.val);
            if(d.j + 1 < arr[d.i].length){
                pq.add(new data(arr[d.i][d.j+1], d.i, d.j+1));
            }
        }
        return ans;
    }
}
