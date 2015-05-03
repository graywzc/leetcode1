#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
    static bool isMatch(const char *s, const char *p) {
        count++;
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

    static bool isMatch1(const char *s, const char *p) {
     // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char* star=NULL;
        const char* ss=s; 
        while (*s){

            count++;
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }

    static int count;
};

int Solution::count = 0;

int main()
{

    //const char *s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    const char *s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    //const char *p = "a*******b";
    const char *p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    Solution::count = 0;
    if(Solution::isMatch1(s,p))
        cout<<"matched "<<Solution::count<<endl;
    else
        cout<<"mismatch "<<Solution::count<<endl;

    Solution::count = 0;
    if(Solution::isMatch(s,p))
        cout<<"matched "<<Solution::count<<endl;
    else
        cout<<"mismatch "<<Solution::count<<endl;
     
}

// this proves that the recursion can be avoided
