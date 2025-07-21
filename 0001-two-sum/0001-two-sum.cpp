class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> a(2);
        for(int i = 0; i<nums.size();i++)
        {
            int d = target - nums[i];
            if(m.find(d) != m.end())
            {
                a[0]=m[d];
                a[1]=i;
                break;

            }
            m[nums[i]]=i;
        }
        return a;
    }
};