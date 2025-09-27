
//Find median in a stream
//https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1


import java.util.*;

class Solution {
    public ArrayList<Double> getMedian(int[] arr) {
        ArrayList<Double> list = new ArrayList<>();
        
        PriorityQueue<Double> pqMin = new PriorityQueue<>(); // larger half
        PriorityQueue<Double> pqMax = new PriorityQueue<>(Collections.reverseOrder()); // smaller half
        
        for (int num : arr) {
            double val = (double) num;
            
            // Step 1: Add to max-heap first
            pqMax.add(val);
            
            // Step 2: Balance -> move the largest of pqMax to pqMin
            pqMin.add(pqMax.poll());
            
            // Step 3: Maintain size property (pqMax >= pqMin)
            if (pqMax.size() < pqMin.size()) {
                pqMax.add(pqMin.poll());
            }
            
            // Step 4: Calculate median
            if (pqMax.size() == pqMin.size()) {
                double d = (pqMax.peek() + pqMin.peek()) / 2.0;
                list.add(d);
            } else {
                list.add(pqMax.peek());
            }
        }
        return list;
    }
}
