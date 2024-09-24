class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set<char> check;
    int left = 0, right = 0, maxLength = 0;
    
    while (right < s.length()) {
        if (check.find(s[right]) == check.end()) {
            // If the character is not in the set, add it and move the right pointer
            check.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        } else {
            // If the character is already in the set, remove the character at 'left' and move 'left'
            check.erase(s[left]);
            left++;
        }
    }
    
    return maxLength;
    }
};