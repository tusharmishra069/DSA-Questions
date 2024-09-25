class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n, 1); //just for storing 

        int start = 1, end = 1;

        for(int i=0; i<n; ++i){
            result[i] = start;
            start *= nums[i];
        }

        for(int i = n - 1; i >= 0; --i){
            result[i] *= end;
            end *= nums[i];
        }
        return result;
    } 
};