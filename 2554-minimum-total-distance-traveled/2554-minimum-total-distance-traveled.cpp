class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
         sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());

    int n = robot.size();
    int m = factory.size();
    
    // DP array where dp[i][j] is the minimum distance to repair the first i robots using the first j factories
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
    dp[0][0] = 0; // Base case: no robots, no factories

    for (int j = 1; j <= m; ++j) {
        dp[0][j] = 0; // No robots means zero distance for any factories
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = dp[i][j - 1]; // Option: skip the j-th factory
            long long cost = 0;
            for (int k = 1; k <= min(i, factory[j - 1][1]); ++k) { // Assign up to factory[j-1][1] robots to factory j-1
                cost += abs((long long)robot[i - k] - factory[j - 1][0]);
                
                // Only update dp[i][j] if dp[i - k][j - 1] is not LLONG_MAX
                if (dp[i - k][j - 1] != LLONG_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                }
            }
        }
    }

    return dp[n][m];
    }
};