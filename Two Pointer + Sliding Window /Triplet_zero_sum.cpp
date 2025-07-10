
/**

Find All Triplets with Zero Sum
https://www.geeksforgeeks.org/problems/find-all-triplets-with-zero-sum/1

**/


class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                int t = arr[i] + arr[j];
                if(mp.count(-t)){
                    for(auto itr : mp[-t]){
                        ans.push_back({itr, i, j});
                    }
                }
            }
            mp[arr[i]].push_back(i);
        }
        return ans;
    }
};
