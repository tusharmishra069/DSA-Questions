class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
         sort(nums.begin(), nums.end());
    // Store numbers in a set for O(1) lookup
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxStreak = 0;

    for (int num : nums) {
        int streak = 0;
        long long current = num; // Use long long to avoid overflow
        // Check if the square sequence exists in the set
        while (numSet.count(current)) {
            streak++;
            current *= current;
            // Break if current exceeds the limit of 10^5 (constraint on nums[i] <= 10^5)
            if (current > 100000) break;
        }
        // Check if the streak is at least 2
        if (streak >= 2) {
            maxStreak = max(maxStreak, streak);
        }
    }

    // Return -1 if no valid streak found
    return maxStreak == 0 ? -1 : maxStreak;
}
};