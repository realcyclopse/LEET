class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m;
        int i= 0;
        int j=0;
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<=nums2[j])
            {
                m.push_back(nums1[i]);
                i++;
            }
            else
            {
                m.push_back(nums2[j]);
                j++;
            }
        }
        if(i<nums1.size())
        {
            while(i<nums1.size())
            {
            m.push_back(nums1[i]);
            i++;
            }
        }
        else if(j<nums2.size())
        {
            while(j<nums2.size())
            {
            m.push_back(nums2[j]);
            j++;
            }
        }

        int n = m.size();
    
        if (n % 2 == 1) {
        // Odd length: return middle element
        return m[n / 2];
    } 
    else {
        // Even length: average of two middle elements
        return (m[n / 2 - 1] + m[n / 2]) / 2.0;

    }
    }
};