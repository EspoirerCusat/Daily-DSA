/**

https://leetcode.com/problems/find-maximum-area-of-a-triangle/

**/


class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        map<long long, set<long long>> Y,X;
        int min_x, max_x, min_y, max_y;
        min_x = max_x = coords[0][0];
        min_y = max_y = coords[0][1];
        for(auto& itr : coords){
            int x = itr[0]; int y = itr[1];
            X[x].insert(y);
            Y[y].insert(x);
            min_x = min(min_x, x);
            max_x = max(max_x, x);
            min_y = min(min_y, y);
            max_y = max(max_y, y);
        }
        long long ans = 0;

        for(auto& itr : X){
            //same x
            long long x1 = itr.first;
            if(itr.second.size() >= 2){
                long long y1 = *itr.second.begin();
                long long y2 = *itr.second.rbegin();
                ans = max({ans, (y2-y1) * abs(max_x - x1), (y2 - y1) * abs(x1 - min_x)});
            }
        }

        for(auto& itr : Y){
            //same y
            long long y1 = itr.first;
            if(itr.second.size() >= 2){
                long long x1 = *itr.second.begin();
                long long x2 = *itr.second.rbegin();
                ans = max({ans, (x2 - x1) * abs(max_y - y1), (x2 - x1) * abs(y1 - min_y)});
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
