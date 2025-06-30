class Solution {
public:
    int bs(vector<int>& nums, int target, int s, int e) {
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) s = m + 1;
            else e = m - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;

            if (nums[low] <= nums[mid]) {
                // left side is sorted
                if (nums[low] <= target && target < nums[mid])
                    return bs(nums, target, low, mid - 1);
                else
                    low = mid + 1;
            } else {
                // right side is sorted
                if (nums[mid] < target && target <= nums[high])
                    return bs(nums, target, mid + 1, high);
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
