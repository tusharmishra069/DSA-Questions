class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);  // Longest Increasing Subsequence up to each element
        vector<int> lds(n, 1);  // Longest Decreasing Subsequence from each element
        
        // Build LIS array
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        
        // Build LDS array
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }
        
        // Find the maximum length of a mountain
        int max_mountain_length = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {  // valid mountain peak
                max_mountain_length = max(max_mountain_length, lis[i] + lds[i] - 1);
            }
        }
        
        // Minimum removals to form a mountain array
        return n - max_mountain_length;
    }
};