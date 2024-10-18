class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size();
    int maxOR = 0;
    for (int num : nums) {
        maxOR |= num; 
    }
    
    int count = 0;
    int totalSubsets = 1 << n; 
    for (int mask = 1; mask < totalSubsets; ++mask) {
        int subsetOR = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { 
                subsetOR |= nums[i];
            }
        }
        if (subsetOR == maxOR) {
            count++; 
        }
    }

    return count;
    }
};