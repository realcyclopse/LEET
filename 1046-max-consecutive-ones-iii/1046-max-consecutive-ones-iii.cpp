class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int z = 0;
        int maxlen = 0;
        int len = 0;
        while(r<nums.size())
        {
            if(nums[r]==0) z++;
            if(z>k)
            {
                if(nums[l]==0) z--;
                l++;
            }
            if(z<=k)
            {
                len = r-l +1;
                maxlen = max(len,maxlen);
            }
            r++;

        }
        return maxlen;


    }
};