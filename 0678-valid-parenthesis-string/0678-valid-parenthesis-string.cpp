class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        for(int i = 0; i< s.length();i++)
        {
            if( s[i] == '(')
            {
                min++;
                max++;
            }
            else if(s[i] == ')')
            {
                min--;
                max--;
            }
            else
            {
                min--;
                max++;
            }
            if(min<0) min = 0;
            if(max<0) return false;
        }
        if(min == 0)
        {
            return true;
        }
        return false;
    }
};