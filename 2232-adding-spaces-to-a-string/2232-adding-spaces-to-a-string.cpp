class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
    int spaceIndex = 0; // Pointer for the spaces array
    int n = spaces.size();
    
    for (int i = 0; i < s.size(); i++) {
        // If the current index matches the next space position, insert a space
        if (spaceIndex < n && i == spaces[spaceIndex]) {
            result += ' ';
            spaceIndex++;
        }
        // Add the current character to the result
        result += s[i];
    }
    return result;
    }
};