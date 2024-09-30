class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> resultSet; 
    for (int num : nums2) {
        if (set1.find(num) != set1.end()) {
            resultSet.insert(num);
        }
    }
    return vector<int>(resultSet.begin(), resultSet.end());
    }
};