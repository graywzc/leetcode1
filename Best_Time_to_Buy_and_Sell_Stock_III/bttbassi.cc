class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2) return 0;                

        vector<int> p1(prices.size(), 0);
        
        int i = 1;
        int lp = prices[0];
        int mp = 0;
        while(i < prices.size())
        {
            if(prices[i] < lp)
                lp = prices[i];
            else if((prices[i]-lp)>mp)
                mp = prices[i]-lp; 
            p1[i] = mp;
            i++; 
        }
        
        i = prices.size() - 2;
        int hp = prices[prices.size()-1];
        while(i >= 0)
        {
            if(prices[i] > hp) 
                hp = prices[i];
            else if((hp-prices[i]+p1[i])>mp)
                mp = hp-prices[i]+p1[i];
            i--; 
        }

        return mp;
    }
};
