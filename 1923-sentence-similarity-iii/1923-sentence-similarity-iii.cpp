class Solution {
public:
    vector<string> splitSentence(const string& sentence) {
    vector<string> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

// Function to check if two sentences are similar
bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> s1 = splitSentence(sentence1);
    vector<string> s2 = splitSentence(sentence2);

    // Ensure that s1 is the longer sentence for easier handling
    if (s1.size() < s2.size()) {
        swap(s1, s2);
    }

    int i = 0, j = 0;
    int n1 = s1.size(), n2 = s2.size();

    // Match from the start of both sentences
    while (i < n2 && s1[i] == s2[i]) {
        i++;
    }

    // Match from the end of both sentences
    while (j < n2 && s1[n1 - 1 - j] == s2[n2 - 1 - j]) {
        j++;
    }

    // Check if all words in s2 were matched either at the start or end of s1
    return i + j >= n2;
}

};