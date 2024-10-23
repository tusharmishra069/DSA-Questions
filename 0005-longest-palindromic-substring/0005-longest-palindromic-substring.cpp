class Solution {
public:
    string expandAroundCenter(const string& s, int left, int right) {
    
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}
    string longestPalindrome(string s) {
         if (s.empty()) return "";

    string longest = "";
    
    for (int i = 0; i < s.size(); ++i) {
        string oddPalindrome = expandAroundCenter(s, i, i);
       
        string evenPalindrome = expandAroundCenter(s, i, i + 1);
        
        if (oddPalindrome.size() > longest.size()) {
            longest = oddPalindrome;
        }
        if (evenPalindrome.size() > longest.size()) {
            longest = evenPalindrome;
        }
    }
    
    return longest;
    }
};