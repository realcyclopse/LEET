class Solution {
public:
    int bestClosingTime(string customers) {
        int curr = 0;
        for(int i =0;i<customers.size();i++)
        {
            if(customers[i] == 'Y') curr++;
        }
        int min = curr;
        int besthour=0;
        for(int i =0;i<customers.size();i++)
        {
            if(customers[i] == 'Y') curr--;
            else curr++;
            if(min>curr)
            {
                min=curr;
                besthour = i + 1;
            }
        }
        return besthour;
    }
};