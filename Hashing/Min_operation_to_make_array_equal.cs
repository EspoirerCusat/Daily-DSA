
/**

https://www.geeksforgeeks.org/dsa/minimum-operation-make-elements-equal-array/

**/

using System;
using System.Collections.Generic;

class HelloWorld {
    static void Main() {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] inputs = Console.ReadLine().Split(); // Read the entire line and split by space
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = Convert.ToInt32(inputs[i]);
        }

        var freqMap = new Dictionary<int, int>();
        int maxFrequency = 0;

        for (int i = 0; i < arr.Length; i++) {
            if (freqMap.ContainsKey(arr[i])) {
                freqMap[arr[i]]++;
            } else {
                freqMap[arr[i]] = 1;
            }
            maxFrequency = Math.Max(maxFrequency, freqMap[arr[i]]);
        }

        Console.WriteLine(n - maxFrequency);
    }
}
