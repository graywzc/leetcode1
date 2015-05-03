#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static string minWindow(string S, string T) {
        string res;        
        if(S.empty() || T.empty() || S.size()<T.size())
            return res;

        unordered_map<char,int> dict;
        for(char t: T)
            dict[t]++;    

        int start = 0, end = 0; 
        unordered_map<char,int> tmp;
        const int size = T.size();
        int count = 0;
        while(end<S.size())
        {
            char cur = S[end];
            if(dict.find(cur)!=dict.end())
            {
                tmp[cur]++;

                if(tmp[cur]<=dict[cur])
                {
                    count++;
                    if(count == size)
                    {
                        char prev = S[start];
                        while(dict.find(prev)==dict.end() || tmp[prev]>dict[prev])        
                        {
                            if (dict.find(prev)!=dict.end()) tmp[prev]--;
                            start++;     
                            prev = S[start];
                        }

                        if(res.empty() || (end-start+1)<res.size())
                            res = S.substr(start, end-start+1);

                        start++;
                        count--;
                        tmp[prev]--;
                    }
                }
            }
            end++; 
        }
        return res;      
    }
};

int main()
{
    string s("caae");
    string t("cae");

    string res = Solution::minWindow(s,t);
    cout<<res.c_str()<<endl;

}
