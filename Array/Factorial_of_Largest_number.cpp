
//https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

class Solution {
  public:
    void f(int n, vector<int>& num){
        int c = 0;
        for(int i=0; i<num.size(); i++){
            int d = n * num[i];
            num[i] = (d + c)%10;
            c = (d + c)/10;
        }
        while(c){
            num.push_back(c%10);
            c /= 10;
        }
    }
    vector<int> factorial(int n) {
        
        vector<int> ans;
        ans.push_back(1);
        for(int i=2; i<=n; i++) f(i, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
