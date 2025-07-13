class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;

        while (l < h) {
            int m = l + (h - l) / 2;

            // Ensure m is even (pointing to first element of a pair)
            if (m % 2 == 1) m--;

            // If pair starts at m, single must be after
            if (nums[m] == nums[m + 1]) {
                l = m + 2;
            } else {
                h = m;
            }
        }

        // l == h is the single element
        return nums[l];
    }
};
