class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        // Step 1: Compute LCS length using DP
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Step 2: Reconstruct the shortest common supersequence (SCS)
        string ans;
        int i = m, j = n;
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) { // Part of LCS
                ans += str1[i - 1];
                --i, --j;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                ans += str1[i - 1];
                --i;
            } else {
                ans += str2[j - 1];
                --j;
            }
        }

        // Add remaining characters from str1 or str2
        while (i > 0) ans += str1[--i];
        while (j > 0) ans += str2[--j];

        reverse(ans.begin(), ans.end());  // Reverse to get the correct order
        return ans;
    }
};
