class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() -1;
        int m = 0;
        while(l<r)
        {
            int water = (r-l) * (min(height[l],height[r]));
            m = max(m,water);
            if(height[l]<height[r])
            {
                l++;
            }
            else r--;
        }
        return m;
        
    }
};