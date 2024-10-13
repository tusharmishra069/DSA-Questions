class Solution {
public:
     bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int maxWordLength = 0;
        for (const string& word : wordDict) {
            if (word.length() > maxWordLength) {
                maxWordLength = word.length();
            }
        }
        
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = max(0, i - maxWordLength); j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break; 
                }
            }
        }
        
        return dp[n];
    }
};