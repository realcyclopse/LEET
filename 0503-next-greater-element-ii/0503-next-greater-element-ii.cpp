class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;
        for(int i = (2*nums.size()) - 1; i>=0 ; i--)
        {
            while(!st.empty() && nums[i%nums.size()]>=st.top())
            {
                st.pop();
            }
            if(i<nums.size())
            {
                if(st.empty())
                {
                    ans[i] = -1;
                }
                else 
                {
                    ans[i] = st.top();
                }
            }
            st.push(nums[i%nums.size()]);
        
        }
        return ans;
    }
};