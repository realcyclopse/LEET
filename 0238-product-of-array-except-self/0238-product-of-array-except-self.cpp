class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;
        for(int i = 1;i<nums.size();i++)
        {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int suff = 1;
        for(int i = nums.size()-2;i>=0;i--)
        {
            suff = suff * nums[i+1];
            ans[i] = suff * ans[i];
        }
        return ans;
        
    }
};