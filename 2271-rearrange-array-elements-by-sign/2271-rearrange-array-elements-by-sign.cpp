class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int a=0;
        int b=1;
        for(int i = 0; i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                res[a]=nums[i];
                a = a + 2;
            }
            else
            {
                res[b]=nums[i];
                b = b + 2; 
            }
        }
        return res;
        
    }
};