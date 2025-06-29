/**

2603. Collect Coins in a Tree
https://leetcode.com/problems/collect-coins-in-a-tree/description/

**/

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        
        int sz = coins.size();
        vector<set<int>> v(sz);
        for(auto& e : edges){
            int x = e[0]; int y = e[1];
            v[x].insert(y);
            v[y].insert(x);
        }

        //Remove all zero wala leaves
        queue<int> q;
        for(int i=0; i<sz; i++){
            if(coins[i] == 0 && v[i].size() <= 1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            int x = *v[f].begin();
            v[f].clear();
            v[x].erase(f);
            if(coins[x] == 0 && v[x].size() == 1){
                q.push(x);
            }
        }

        //Remove Leave wih 1 
        while (!q.empty()) {
            q.pop();
        }
        for(int i=0; i<sz; i++){
            if(v[i].size() == 1 && coins[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int f = q.front();
            q.pop();
            int x = *v[f].begin();
            v[f].clear();
            v[x].erase(f);
        }

        //Remove Leave with 0
        while (!q.empty()) {
            q.pop();
        }
        for(int i=0; i<sz; i++){
            if(v[i].size() == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int f = q.front();
            q.pop();
            int x = *v[f].begin();
            v[f].clear();
            v[x].erase(f);
        }

        int cnt = 0;
        for(int i=0; i<sz; i++){
            if(v[i].size() == 0) cnt++;
        }

        return max(0, 2 * (sz - cnt - 1));
        
    }
};
