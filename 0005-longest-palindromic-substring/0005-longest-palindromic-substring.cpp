class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        int start = 0, maxlen = 1;
        int n = s.size();

        auto expand = [&](int l, int r){
            while (l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxlen){
                    start = l;
                    maxlen = r -l + 1;
                }
                l--;
                r++;
            }
        };

        for (int i =0; i < n; i++){
            expand(i,i); //odd length
            expand(i, i+1); //even length
        }
        return s.substr(start, maxlen);
    }
};