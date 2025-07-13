class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0],nums[1]);
        else
        {
            int l = 0;
            int h = n-1;
            int m = (l+h)/2;
            int ans = INT_MAX;
            while(l<=h)
            {
                if(nums[m]>=nums[l] )
                {
                    ans = min(ans,nums[l]);
                    l = m + 1;
                    m = (l+h)/2;
                }
                else if (nums[h]>=nums[m])
                {
                    ans = min(ans,nums[m]);
                    h = m - 1;
                    m = (l+h)/2;
                }
                else if(nums[m]>=nums[l] && nums[h]>=nums[m])
                {
                    return nums[l];
                }
            }
            return ans;
        }
        
    }
};