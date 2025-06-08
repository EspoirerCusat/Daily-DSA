
//https://leetcode.com/problems/maximum-good-subtree-score/

class Solution {
public:

    long long mod = 1e9 + 7;

    void dfs(int src, int par, vector<vector<int>>& adj, vector<int>& val, vector<vector<int>>& nodes){
        nodes[src].push_back(val[src]);
        for(auto nbr : adj[src]){
            if(nbr != par){
                dfs(nbr, src, adj, val, nodes);
                nodes[src].insert(nodes[src].end(), nodes[nbr].begin(), nodes[nbr].end());
            }
        }
    }

    bool check(int x, int freq){
        while(x){
            int res = x%10;
            if((1<<res)&freq){
                return false;
            }else{
                freq |= (1 << res);
            }
            x /= 10;
        }
        return true;
    }
    int combine(int x, int freq){
        while(x){
            int res = x%10;
            freq |= (1 << res);
            x /= 10;
        }
        return freq;
    }

    //Knap-sack
    long long f(int i, int freq, vector<int>& node, vector<vector<long long>>& dp){
        if(i >= node.size()) return 0;
        if(dp[i][freq] != -1) return dp[i][freq];

        long long res = f(i+1, freq, node, dp);
        if(check(node[i], freq)){
            long long take = (long long)node[i] + f(i+1, combine(node[i], freq), node, dp);
            res = max(res, take);
        }

        return dp[i][freq] = res;
    }
    
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n = par.size();
        vector<vector<int>> adj(n + 5);
        for(int i=1; i<n; i++){
            int u = i; int v = par[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long sum = 0;
        vector<vector<int>> nodes(n + 5);
        dfs(0, -1, adj, vals, nodes);
      
        for(int i=0; i<n; i++){
            int N = nodes[i].size();
            //cout<<N<<" ";
            int freq = 0;
            vector<vector<long long>> dp(N, vector<long long>(1025, -1));
            long long res = f(0, freq, nodes[i], dp);
            sum = (sum%mod + res%mod)%mod;
        }
        return sum;
    }
};
