// TC: O(m*n) + O(2(m+n)))
// SC: O(m*n)
#include <bits/stdc++.h>
using namespace std;

string shortestSupersequence(string a, string b) {
    int m=a.size(), n=b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m;i++){
        for(int j=1;j<=n;j++){
            if (a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans="";
    int i=m, j=n;
    while(i>0 && j>0){
        if (a[i-1]==b[j-1]) ans+=a[i-1], i--, j--;
        else if (dp[i-1][j]>dp[i][j-1]) ans+=a[i-1], i--;
        else ans+=b[j-1], j--;
    }
    while(i>0) ans+=a[i-1], i--;
    while(j>0) ans+=b[j-1], j--;
    reverse(ans.begin(), ans.end());
    return ans;
}

string shortestCommonSupersequence(string str1, string str2) {
    int m=str1.size(), n=str2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m;i++){
        for(int j=1;j<=n;j++){
            if (str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string ans="";
    int i=m, j=n;
    while(i>0 && j>0){
        if (str1[i-1]==str2[j-1]) ans+=str1[i-1], i--, j--;
        else if (dp[i-1][j]>dp[i][j-1]) ans+=str1[i-1], i--;
        else ans+=str2[j-1], j--;
    }
    while(i>0) ans+=str1[i-1], i--;
    while(j>0) ans+=str2[j-1], j--;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}