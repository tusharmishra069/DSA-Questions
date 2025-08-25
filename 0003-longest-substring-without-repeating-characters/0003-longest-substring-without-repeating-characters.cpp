class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1);  // stores last seen index of chars
        int maxLen = 0;
        int left = 0;  // sliding window left pointer

        for (int right = 0; right < s.size(); right++) {
            if (lastIndex[s[right]] >= left) {
                // character already seen, move left
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right;  // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
