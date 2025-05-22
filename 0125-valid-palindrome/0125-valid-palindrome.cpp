class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        for (int i = 0; i < s.length(); i++) 
        {
            char c = s[i];
            if (isalpha(c))
            {
                result += tolower(c);
            } 
            else if (isdigit(c))
            {
                result += c;
            }
        }
        int ss=0;
        int e=result.length() - 1;
        while(ss<=e)
        {
            if(result[ss]!=result[e])
            {
                return false;
            }
            ss++;
            e--;
        }
        return true;
    }
};