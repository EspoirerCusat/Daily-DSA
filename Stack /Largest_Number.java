
//Largest Number
//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/largest-number-7-eee0b7c3/

/***
Problem
Given an integer N with D digits without any leading zeroes. Find the largest number which can be obtained by deleting exactly K digits from the number N.
**/

import java.util.*;
 
class Solution {
    public String largestNumberAfterKRemovals(String num, int k) {
        Stack<Character> stack = new Stack<>();
        
        for (char c : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peek() < c) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
 
        while (k > 0 && !stack.isEmpty()) {
            stack.pop();
            k--;
        }
 
        StringBuilder sb = new StringBuilder();
        for (char c : stack) {
            sb.append(c);
        }
 
        return sb.length() == 0 ? "0" : sb.toString();
    }
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num = sc.next();  
        int k = sc.nextInt();   
        
        Solution sol = new Solution();
        System.out.println(sol.largestNumberAfterKRemovals(num, k));
    }
}
