class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());  // normalize by sorting
            mp[key].push_back(s);          // group by sorted string
        }

        vector<vector<string>> result;
        for (auto& [key, group] : mp) {
            result.push_back(group);
        }

        return result;
    }
};
