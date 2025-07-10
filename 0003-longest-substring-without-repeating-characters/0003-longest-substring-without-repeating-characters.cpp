class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int n = s.size();
        unordered_map <char,int> m;
        while(r < n)
        {
            if (m.find(s[r]) == m.end())
            {
                m[s[r]]++;
                maxlen = max(maxlen,r - l + 1);
                r++;
            }
            else
            {
                m.erase(s[l]);
                l++;

            }
        }
        return maxlen;


        
    }
};