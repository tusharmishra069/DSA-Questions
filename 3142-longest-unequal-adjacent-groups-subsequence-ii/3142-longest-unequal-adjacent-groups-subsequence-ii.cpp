class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        
        auto canFormSequence = [](const string& left, const string& right) {
            if (left.size() != right.size()) return false;
            int diffCount = 0;
            for (int i = 0; i < left.size(); ++i) {
                if (left[i] != right[i]) ++diffCount;
            }
            return diffCount == 1;
        };

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxLength = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && canFormSequence(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if (dp[i] > maxLength) {
                        maxLength = dp[i];
                        lastIndex = i;
                    }
                }
            }
        }

        vector<string> result;
        for (int i = lastIndex; i != -1; i = prev[i]) {
            result.push_back(words[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};