class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int>freq;

        for(char c:s){
            freq[c]++;
        }

        vector<pair<char,  int>> v(freq.begin(), freq.end());

        sort(v.begin(), v.end(), [](pair<char, int>&a, pair<char,int>&b){
            return a.second > b.second;
        });

        string result = "";
        for (auto p : v) {
            result += string(p.second, p.first);
        }

        return result;
    }
};