class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        assert(s&&p);    
        if(*p == '?')
            return *s && isMatch(s+1,p+1);
        else if(*p == '\0')
            return *s=='\0';
        else if(*p == '*')
        {
            if(*(p+1) == '*')
            {
                return isMatch(s,p+1); 
            }

            while(1) 
            {
                if(isMatch(s,p+1)) return true; 
                if(*s=='\0') break;
                s++;
            }
            return false;
        }
        else
            return *s==*p && isMatch(s+1,p+1);
    }
};
// this algorithm uses recursion, cannot meet performance
