
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    // Step 1: Build LCS DP table
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Step 2: Build SCS string
    int i = n, j = m;
    string ans = "";

    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            // common character
            ans += str1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            // take from str1
            ans += str1[i-1];
            i--;
        } else {
            // take from str2
            ans += str2[j-1];
            j--;
        }
    }

    // remaining characters
    while(i > 0) {
        ans += str1[i-1];
        i--;
    }

    while(j > 0) {
        ans += str2[j-1];
        j--;
    }

    // reverse because we built backwards
    reverse(ans.begin(), ans.end());

    return ans;
}

// Example usage
int main() {
    string str1 = "abac";
    string str2 = "cab";

    cout << shortestCommonSupersequence(str1, str2);

    return 0;
}