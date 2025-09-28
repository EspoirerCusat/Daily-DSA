
//https://leetcode.com/problems/merge-intervals/

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if(a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });
        int idx = 0;
        ArrayList<int[]> res = new ArrayList<>();
        int n = intervals.length;
        while(idx < n){
            int s = intervals[idx][0];
            int e = intervals[idx][1];
            while(idx < n-1 && e >= intervals[idx+1][0]){
                e = Math.max(e, intervals[idx+1][1]);
                idx++;
            }
            res.add(new int[]{s, e});
            idx++;
        }
        int[][] ans = new int[res.size()][2];
        idx = 0;
        for(int[] x : res){
            ans[idx++] = x;
        }
        return ans;
    }
}
