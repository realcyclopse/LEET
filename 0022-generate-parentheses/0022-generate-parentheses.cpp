class Solution {
public:
    void gen(int n,int cop,int ccl, string curr,vector<string> &ans)
    {   
        if(curr.size() == 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(cop<n)
        {
            string temp = curr;
            temp+="(";
            gen(n,cop+1,ccl,temp,ans);
        }
        if(ccl<cop)
        {   string temp = curr;
            temp+=")";
            gen(n,cop,ccl+1,temp,ans);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int cop = 0;
        int ccl = 0;
        vector<string> ans;
        string curr = "";
        gen(n,cop,ccl,curr,ans);
        return ans;
    }
};