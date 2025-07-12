

/**

Substrings with K Distinct
https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1


**/


class Solution {
    //At most k distinct 
    public int f(string s, int k){
        if(k == 0) return 0;
        int n = s.Length;
        //var map = new Dictionary<char,int>();
        int[] map = new int[26];
        int i = 0; int j = 0;
        int cnt = 0; int dist = 0;
        while(j < n){
            //if(!map.TryAdd(s[j], 1)) map[s[j]]++;
            if(map[s[j] - 'a'] == 0) dist++;
            map[s[j] - 'a']++;
            
            while(dist > k){
                map[s[i] - 'a']--;
                if(map[s[i] - 'a'] == 0){
                    dist--;
                }
                i++;
            }
            cnt += j - i + 1;
            
            j++;
        }
        return cnt;
    }
    public int countSubstr(string s, int k) {
        return f(s, k) - f(s, k-1);
    }
}
