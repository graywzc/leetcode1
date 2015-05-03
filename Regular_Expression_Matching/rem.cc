class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p=='\0')        
            return *s==*p;
        else if(*(p+1)=='*')
        {
            if(isMatch(s,p+2)) return true; 
            if(*p!='.')
            {
                while(*s==*p) 
                {
                    if(isMatch(s+1,p+2)) return true;  
                    s++;
                }
            }
            else
            {
                while(*s) 
                {
                    if(isMatch(s+1,p+2)) return true;
                    s++;
                }
            }
            return false;
        }
        else 
            return (*s==*p || (*p=='.'&&*s!='\0')) && isMatch(s+1,p+1);
    }
};
