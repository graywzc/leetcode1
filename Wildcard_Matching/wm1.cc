class Solution {
public:
    bool isMatch(const char *s, const char *p) {
       
        const char* star=NULL;
        const char* ss=NULL;
        while(*s) 
        {
            if(*s == *p || *p == '?')   
            {
                s++; p++; 
                continue;
            }
            if(*p == '*')
            {
                star = p++;  
                ss = s;
                continue;
            }
            if(star)
            {
                p = star+1;
                s = ++ss;
                continue;
            }
            return false;
        }

        while(*p)
        {
            if(*p=='*') 
                p++;
            else
                return false;
        }

        return true;
    }
};
