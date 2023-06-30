// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2) {
    int m=str1.length(), n=str2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int i=m, j=n, ans=0;
    while(dp[i][j]){
        if (str1[i-1]==str2[j-1]) i--, j--;
        else if (dp[i-1][j-1]==dp[i][j]) i--, j--, ans++;
        else if (dp[i-1][j]>dp[i][j-1]) i--, ans++;
        else j--, ans++;
    }
    return ans + max(i, j);
}

int main() {
/*
wncpoddas
wqegesggfff
*/
    // string str1="wncpoddas", str2="wqegesggfff";
    string str1="execution", str2="intention";
    cout<<editDistance(str1, str2)<<endl;
    return 0;
}