class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)        
            return 0;
        int mp = 0;
        int i = 1;
        while(i < prices.size())
        {
            if(prices[i]>prices[i-1])
                mp += (prices[i] - prices[i-1]);
            i++; 
        }
        return mp;
    }
};
