class Solution {
public:
    bool search(vector<int>& num, int target) {
        int l = 0,r = num.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (num[mid] == target) return true;

            // Handle duplicates
            if (num[l] == num[mid] && num[mid] == num[r]) {
                l++;
                r--;
            }
            else if (num[l] <= num[mid]) { // Left half is sorted
                if (target >= num[l] && target < num[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { // Right half is sorted
                if (target > num[mid] && target <= num[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};