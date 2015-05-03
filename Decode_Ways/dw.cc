class Solution {
public:
    int numDecodings(string s) {
        
        if(s.empty()) return 0; 

        vector<int> nd(s.size(),0);

        for(int i = nd.size()-1; i >= 0; i--)
        {
            if('1'<=s[i] && s[i]<='9') 
            {
                if((i+1)<nd.size())
                {
                    nd[i] += nd[i+1];     
                    if(s[i] == '1' || (s[i]=='2' && '0'<=s[i+1] && s[i+1]<='6'))
                        nd[i] += ((i+2)<nd.size())?nd[i+2]:1;
                }
                else
                    nd[i] += 1;
            }
        }

        return nd[0];
    }
};
