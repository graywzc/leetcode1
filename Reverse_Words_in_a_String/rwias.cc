class Solution {
public:
    void reverseWords(string &s) {
        string temp;

        int i = s.size()-1;
        while(i>=0)
        {
            while(i>=0 && isspace(s[i]))
                i--;
            if(i<0) break;

            int j = i-1;
            while(j>=0 && !isspace(s[j]))
                j--;

            temp=temp+' '+s.substr(j+1,i-j);    
            i = j; 
        }
        s = temp.empty()?temp:temp.substr(1);
    }
};
