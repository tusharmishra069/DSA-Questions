class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    // Frequency array for s1 and window in s2
    vector<int> s1Freq(26, 0), s2Freq(26, 0);

    // Fill frequency for the first window in s2 and for s1
    for (int i = 0; i < s1.length(); i++) {
        s1Freq[s1[i] - 'a']++;
        s2Freq[s2[i] - 'a']++;
    }

    // Compare the frequency 
    if (s1Freq == s2Freq) return true;

    for (int i = s1.length(); i < s2.length(); i++) {
        s2Freq[s2[i] - 'a']++;
        s2Freq[s2[i - s1.length()] - 'a']--;

        if (s1Freq == s2Freq) return true;
    }

    return false;
    }
};