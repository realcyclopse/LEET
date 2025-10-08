class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int n = spells.size();
        int m = potions.size();

        for (int i = 0; i < n; i++) {
           
            long long need = (success + spells[i] - 1) / spells[i];

            auto it = lower_bound(potions.begin(), potions.end(), need);
            int pos = it - potions.begin();
            ans.push_back(m - pos);  
        }
        return ans;
    }
};

