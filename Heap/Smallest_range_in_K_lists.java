
//Smallest range in K lists
//https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1

import java.util.*;

class Node {
    int data;
    int row;
    int col;

    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
}

class Solution {
    public ArrayList<Integer> findSmallestRange(int[][] arr) {
        int n = arr.length;

        PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> a.data - b.data); // min-heap

        int maxi = Integer.MIN_VALUE;
        int mini = Integer.MAX_VALUE;

        // push the first element of each row
        for (int i = 0; i < n; i++) {
            int element = arr[i][0];
            maxi = Math.max(maxi, element);
            mini = Math.min(mini, element);
            pq.add(new Node(element, i, 0));
        }

        int start = mini, end = maxi;

        while (true) {
            Node temp = pq.poll(); // get min
            mini = temp.data;

            // update range if smaller
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // move to next element in same row
            if (temp.col + 1 < arr[temp.row].length) {
                int next = arr[temp.row][temp.col + 1];
                maxi = Math.max(maxi, next);
                pq.add(new Node(next, temp.row, temp.col + 1));
            } else {
                break; // one row is exhausted
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(start);
        ans.add(end);
        return ans;
    }
}
