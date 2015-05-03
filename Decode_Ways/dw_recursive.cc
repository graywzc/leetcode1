class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        if(s.empty()) return res;

        if('1' <= s[0] && s[0] <= '9')
        {
            res += numDecodings(s.substr(1)); 
            if(s.size()>=2)
            {
                if(s[0] == '1' || 
                   (s[0] == '2' && '0' <= s[1] && s[1]<='6')) 
                   res += numDecodings(s.substr(2));
            }
        }

        return res;
    }
};
