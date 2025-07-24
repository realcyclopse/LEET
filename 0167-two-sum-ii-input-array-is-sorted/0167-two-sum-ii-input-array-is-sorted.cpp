class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = 1;
        vector<int> ans(2);
        while(j<numbers.size())
        {
            if(numbers[i]+numbers[j] == target)
            {
                ans[0] = i+1;
                ans[1] = j+1;
                break;
            }
            else if(numbers[i]+numbers[j] < target)
            {
                i++;
                j++;
            }
            else
            {
                i--;
            }
        }
        return ans;
    }
};