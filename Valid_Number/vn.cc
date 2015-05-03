class Solution {
public:
    bool isNumber(const char *s) {
        if(s == NULL)
            return false;

        while(*s && *s==' ')        
            s++;

        while(*s == '+' || *s == '-') 
            s++;

        bool e_existed = false;
        bool right_after_e = false;
        bool num_before_e = false;
        bool num_after_e = false;
        bool one_dot = false;

        while(*s)
        {
            if(isdigit(*s))
            {
                right_after_e = false;
                if(!e_existed)
                    num_before_e = true;
                else
                    num_after_e = true;
            }
            else if(*s == 'e')
            {
                if(e_existed || !num_before_e) 
                    return false;
                e_existed = true;
                right_after_e = true;
            }
            else if(*s == '.')
            {
                if(e_existed || one_dot)
                    return false;
                one_dot = true;    
            }
            else if(*s == '+' || *s == '-')
            {
                if(!right_after_e) 
                    return false;
                right_after_e = false;
            }
            else if(*s == ' ')
            {
                break;
            }
            else
                return false;
            s++; 
        }

        if(!num_before_e || (e_existed && !num_after_e))
            return false;

        while(*s)
        {
            if(*s!=' ')
                return false;
            s++; 
        }

        return true;
    }
};
