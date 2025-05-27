class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num2=0;
        if(1<=m && m<=n)
        {
            for(int i=1;i*m<=n;i++)
            {
                num2 = num2 + i*m;
            }
        }
        int sum= n*(n+1)/2;
        return sum - (num2*2);

        
    }
};