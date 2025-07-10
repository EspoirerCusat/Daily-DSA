
/**

https://www.geeksforgeeks.org/dsa/sum-of-elements-in-an-array-with-frequencies-greater-than-or-equal-to-that-element/

**/


using System;
using System.Collections.Generic;
using System.Collections;

class HelloWorld {
  static void Main() {

    int n = Convert.ToInt32(Console.ReadLine());
    string[] input = Console.ReadLine().Split(" ");
    int[] arr = new int[n];
    for(int i=0; i<n; i++){
        arr[i] = Convert.ToInt32(input[i]);
    }
    
    var map = new Dictionary<int,int>();
    for(int i=0; i<n; i++){
        if(map.ContainsKey(arr[i]))
            map[arr[i]]++;
        else
            map[arr[i]] = 1;
    }
    int ans = 0;
    
    //Element frequency is greater than elemnt value
    foreach(KeyValuePair<int,int> kvp in map){
        if(kvp.Key <= kvp.Value){
            ans += kvp.Key;
        }
    }
    Console.WriteLine(ans);
  }
}








