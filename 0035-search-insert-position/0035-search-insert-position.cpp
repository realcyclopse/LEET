class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        if(target > nums[e]) return n;
        while (s<=e)
        {
            int mid = (s + e)/2;
            if(nums[mid]==target) return mid;
            if(target < nums[mid])
            {
                e = mid -1;
            }
            else s = mid+1;
        }
        return s;
    }
};