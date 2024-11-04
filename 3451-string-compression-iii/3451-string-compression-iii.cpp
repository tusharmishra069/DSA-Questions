class Solution {
public:
    string compressedString(string word) {
    string comp;
    int n = word.length();
    int i = 0;

    while (i < n) {
        char c = word[i];
        int count = 0;

        // Count occurrences of character 'c', up to a maximum of 9
        while (i < n && word[i] == c && count < 9) {
            count++;
            i++;
        }

        // Append the count and character to the result
        comp += to_string(count) + c;
    }

    return comp;
    }
};