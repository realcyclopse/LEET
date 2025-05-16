class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pmax=0;
        int p;
        int buy=0;
        int sell=1;
        while(buy<prices.size() && sell<prices.size())
        {
            if(prices[buy]>=prices[sell])
            {
                buy=sell;
                sell++;
            }
            else if(prices[buy]<prices[sell])
            {
                p=prices[sell]-prices[buy];
                if(p>pmax)
                {
                    pmax=p;
                }
                sell++;
            }
        }
        return pmax;
    }
};