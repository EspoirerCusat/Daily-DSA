

import java.util.*;
public class Solution
{
    public static ArrayList<Integer> findCommonElements(ArrayList<ArrayList<Integer>> mat)
    {
        Map<Integer, Integer> mp = new HashMap<>();
        int n = mat.size();
        int m = mat.get(0).size();

        ArrayList<Integer> ans = new ArrayList<>();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mp.getOrDefault(mat.get(i).get(j), 0) == i){
                    mp.put(mat.get(i).get(j), mp.getOrDefault(mat.get(i).get(j), 0) + 1);
                }
            }
        }

        for(Integer key : mp.keySet()){
            if(mp.get(key) == n){
                ans.add(key);
            }
        }

        return ans;
    }
}
