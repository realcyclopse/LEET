class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> m;
        m[5] = 0;
        m[10] = 0;
        m[20] = 0;
        int i = 0;
        while(i<bills.size())
        {
            m[bills[i]]++;
            int ch = bills[i] - 5;
            if(ch == 0) {
                i++; 
                continue;
            }
            else if(ch == 5)
            {
                if(m[5]>0)
                {
                    m[5]--;
                    i++;
                    continue;
                }
                else return false;
            }
            else if (ch==15)
            {
                if(m[5]>0 && m[10]>0)
                {
                    m[5]--;
                    m[10]--;
                    i++;
                }
                else if(m[5] >= 3)
                {
                    m[5] = m[5] - 3;
                    i++;
                }
                
                else return false;
            }
        }
        return true;
    }
};