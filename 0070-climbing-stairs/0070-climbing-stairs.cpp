class Solution {
public:
vector<int> mem;
    int climbStairs(int n) {
        if(mem.size()==0) mem.assign(n+1,-1);
        if (n == 1) return 1;
        if (n == 2) return 2;
        if(mem[n]==-1) 
        {
            mem[n] = climbStairs(n - 1) + climbStairs(n - 2);
        }
        return mem[n];
    }
};
