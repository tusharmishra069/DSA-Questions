class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        // Count the occurrences of each remainder when divided by k
        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) rem += k;  // Handle negative numbers
            remainderCount[rem]++;
        }

        // Check the remainder pairs
        for (auto& [rem, count] : remainderCount) {
            if (rem == 0) {
                // Numbers with remainder 0 must pair with themselves, so the count should be even
                if (count % 2 != 0) return false;
            } else {
                // Numbers with remainder rem must pair with numbers with remainder k - rem
                int complement = k - rem;
                if (remainderCount[complement] != count) return false;
            }
        }
        
        return true;
    }
};