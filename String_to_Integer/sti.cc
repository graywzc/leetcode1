class Solution {
public:
    int atoi(const char *str) {
// 1. null
// 2. space before and after
// 3. '-', '+'
// 4. ignore non-numerical trailing char
// 5. valid string must have numerical char
// 6. return 0 for invalid, cap num which is out of bound

        if(str == NULL) return 0;

        while(isblank(*str))
            str++;

        bool isNeg = false;
        if(*str == '+')
            str++;
        else if(*str == '-')
        {
            isNeg = true;
            str++; 
        }
        
        double res = 0;
        while(isdigit(*str))
        {
            res*=10;
            res+=*str-'0';
            if(!isNeg && res>INT_MAX) return INT_MAX;
            else if(isNeg && (-res)<INT_MIN) return INT_MIN;
            str++; 
        }

        if(isNeg) res*=-1;

        return res;
    }
};
