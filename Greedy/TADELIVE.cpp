

// https://www.codechef.com/problems/TADELIVE

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int f(int i, int x, int y, int n, int A[], int B[], int dp[MAXN][MAXN][MAXN]) {
    if (x <= 0 || y <= 0 || i >= n) return 0;
    if (dp[i][x][y] != -1) return dp[i][x][y];

    int pickA = A[i] + f(i + 1, x - 1, y, n, A, B, dp);
    int pickB = B[i] + f(i + 1, x, y - 1, n, A, B, dp);

    return dp[i][x][y] = max(pickA, pickB);
}

void solvedp() {
    int n, x, y;
    cin >> n >> x >> y;

    int A[n], B[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    // Declare the DP array with max bounds
    int dp[MAXN][MAXN][MAXN];
    memset(dp, -1, sizeof(dp));

    int ans = f(0, x, y, n, A, B, dp);
    cout << ans << "\n";
}

void solveGreedy(){
    int n, x, y;
    cin >> n >> x >> y;

    int A[n], B[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    
    //Let's choose all to B
    int sum = 0;
    for(int i=0; i<n; i++) sum += B[i];
    
    vector<int> diff(n); 
    for(int i=0; i<n; i++) diff[i] = A[i] - B[i];
    sort(diff.begin(), diff.end(), greater<int>());
    
    int ans = (y >= n) ? sum : INT_MIN;
    
    int pre = 0;
    for(int i=0; i<n; i++){
        pre += diff[i];
        if(i < x && n - i - 1 <= y){
            ans = max(ans, sum + pre);
        }
    }
    cout<<ans<<"\n";
}

int main() {
    
    solveGreedy();

}
