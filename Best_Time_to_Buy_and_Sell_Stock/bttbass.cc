class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)        
            return 0;
        int mp = 0;
        int low = prices[0];
        int i = 1;
        while(i < prices.size())
        {
            if(prices[i] > low)
            {
                int local = prices[i] - low;
                if(local > mp)
                    mp = local;
            }
            else if(prices[i] < low)
                low = prices[i];
            i++; 
        }
        return mp;
    }
};
