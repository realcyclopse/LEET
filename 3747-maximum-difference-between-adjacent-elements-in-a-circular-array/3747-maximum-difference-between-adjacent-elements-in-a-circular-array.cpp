class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int i = 0;
        int j=1;
        int maxdiff=0;
        int diff;
        
        while(i<j || (j==0 && (i==nums.size()-1) ) )
        {
            diff = abs(nums[i] - nums[j]);
            if(diff>maxdiff)
            {
                maxdiff = diff;
            }
            if(j==nums.size()-1)
            {
                j=0;
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }
        return maxdiff;
        
    }
};