class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; 
        stack<int> st;
        unordered_map<int, int> umap;
        for(int i = nums2.size() -1; i>=0;i--)
        {
            int el = nums2[i];
            while(!st.empty() && st.top()<el)
            {
                st.pop();
            }
            if(st.empty())
            {
                umap[el] = -1;
            }
            else umap[el] = st.top();
            st.push(el);
        }
        for(int i =0 ; i<nums1.size(); i++)
        {
            ans.push_back(umap[nums1[i]]);
        }
        return ans;
    }
};
