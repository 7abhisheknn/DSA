// TC: O(m*n)
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

bool wildcardMatching(string pattern, string text) {
    int m = text.size(), n = pattern.size();
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    dp[0][0] = true;
    for(int j=1; j<=n && pattern[j-1]=='*'; j++) dp[0][j] = true;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            if (pattern[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else if (pattern[j-1]=='?' || text[i-1]==pattern[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = false;
        }
    return dp[m][n];
}

int main() {
    /*
*bc*da?*
abccdazzz
    */
    cout << wildcardMatching("*bc*da?*", "abccdazzz");
    return 0;
}