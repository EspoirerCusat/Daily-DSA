//2462. Total Cost to Hire K Workers
//https://leetcode.com/problems/total-cost-to-hire-k-workers/description/

class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        long ans = 0L;
        int n = costs.length;

        // Min-heap: (cost, index)
        PriorityQueue<int[]> start = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });

        PriorityQueue<int[]> last = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });

        int i = 0, j = n - 1;

        // Fill left heap
        while (i < candidates && i < n) {
            start.offer(new int[]{costs[i], i});
            i++;
        }

        // Fill right heap
        while (j >= i && j >= n - candidates) {
            last.offer(new int[]{costs[j], j});
            j--;
        }

        for (int idx = 0; idx < k; idx++) {
            if (!start.isEmpty() && !last.isEmpty()) {
                if (start.peek()[0] <= last.peek()[0]) {
                    ans += start.poll()[0];
                    if (i <= j) {
                        start.offer(new int[]{costs[i], i});
                        i++;
                    }
                } else {
                    ans += last.poll()[0];
                    if (i <= j) {
                        last.offer(new int[]{costs[j], j});
                        j--;
                    }
                }
            } else if (!start.isEmpty()) {
                ans += start.poll()[0];
                if (i <= j) {
                    start.offer(new int[]{costs[i], i});
                    i++;
                }
            } else {
                ans += last.poll()[0];
                if (i <= j) {
                    last.offer(new int[]{costs[j], j});
                    j--;
                }
            }
        }

        return ans;
    }
}
