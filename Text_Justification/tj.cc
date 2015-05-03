#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
    static vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;

        int i = 0;
        while(i<words.size())
        {
            while(i < words.size() && words[i].empty())
                i++;
            if(i == words.size()) break;

            assert(words[i].size()<=L);
            int count = words[i].size();

            int j = i+1;
            int nspace = 0;
            while(j<words.size() && (count+1+words[j].size())<=L)
            {
                if(!words[j].empty())
                {
                    count += (1+words[j].size());
                    nspace++;
                }
                j++;
            }

            if(j == words.size()) 
            {
                int k = i; 
                string temp;
                temp+=words[k];
                k++;
                while(k < j)
                {
                    if(!words[k].empty())
                    {
                        temp+=" "; 
                        temp+=words[k];
                    }
                    k++;
                }
                if(L>count)
                    temp.append(L-count,' ');
                res.push_back(temp);
                
            }
            else
            {
                if(nspace==0) 
                {
                    string temp(words[i]);
                    if(L>count)
                        temp.append(L-count,' ');
                    res.push_back(temp);
                }
                else
                {
                    int extra = L-count;
                    int nmore = extra%nspace;

                    string temp;
                    temp+=words[i];
                    int k = i+1;
                    while(k<j)
                    {
                        if(!words[k].empty())
                        {
                            if(nmore>0)  
                            {
                                temp.append(extra/nspace+2,' ');  
                                nmore--;
                            }
                            else
                                temp.append(extra/nspace+1,' ');

                            temp+=words[k];
                        }
                        k++; 
                    }
                    res.push_back(temp);
                }
            }
            i = j;
        }
        
        if(res.empty() && !words.empty())
            res.push_back(string(L,' '));
        return res;
    }
};

int main()
{
    int L = 2;
    vector<string> words;
    words.push_back("a");

    vector<string> res = Solution::fullJustify(words, L);
}
