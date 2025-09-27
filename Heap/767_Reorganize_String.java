//767. Reorganize String
//https://leetcode.com/problems/reorganize-string/description/

class Solution {
    static class Node implements Comparable<Node>{
        public int cnt;
        public char c;
        Node(int cnt, char c){
            this.cnt = cnt;
            this.c = c;
        }
        public int compareTo(Node other){
            if(this.cnt == other.cnt) 
                return Character.compare(this.c, other.c);
            return Integer.compare(other.cnt, this.cnt);
        }
    }
    public String reorganizeString(String s) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        StringBuilder res = new StringBuilder();

        Map<Character, Integer> mp = new HashMap<>();
        for(char c : s.toCharArray()){
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        for(Character c : mp.keySet()){
            pq.add(new Node(mp.get(c), c));
        }

        while(pq.size() >= 2){
            Node node1 = pq.poll();
            Node node2 = pq.poll();

            res.append(node1.c);
            res.append(node2.c);

            if(node1.cnt-1 > 0) pq.add(new Node(node1.cnt-1, node1.c));
            if(node2.cnt-1 > 0) pq.add(new Node(node2.cnt-1, node2.c));
        }

        if(!pq.isEmpty()){
            Node node = pq.poll();
            if(node.cnt > 1) return "";
            res.append(node.c);
        }

        return res.toString();
    }
}


//Other way to do same


public class Solution {
    public String reorganizeString(String s) {
        HashMap<Character, Integer> freqMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        PriorityQueue<Character> maxHeap = new PriorityQueue<>((a, b) -> freqMap.get(b) - freqMap.get(a));
        maxHeap.addAll(freqMap.keySet());

        StringBuilder res = new StringBuilder();
        while (maxHeap.size() >= 2) {
            char char1 = maxHeap.poll();
            char char2 = maxHeap.poll();

            res.append(char1);
            res.append(char2);

            freqMap.put(char1, freqMap.get(char1) - 1);
            freqMap.put(char2, freqMap.get(char2) - 1);

            if (freqMap.get(char1) > 0) maxHeap.add(char1);
            if (freqMap.get(char2) > 0) maxHeap.add(char2);
        }

        if (!maxHeap.isEmpty()) {
            char ch = maxHeap.poll();
            if (freqMap.get(ch) > 1) return "";
            res.append(ch);
        }

        return res.toString();
    }
}
