// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n,-1));
    for(int i=0;i<m;i++) dp[i][0]=1;
    for(int j=0;j<n;j++) dp[0][j]=1;

    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            dp[i][j]=dp[i-1][j] + dp[i][j-1];
    
    return dp[m-1][n-1];
}

int main() {
    cout<<uniquePaths(2,2)<<endl;
    cout<<uniquePaths(3,2)<<endl;
    cout<<uniquePaths(1,1)<<endl;
    return 0;
}