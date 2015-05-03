class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int lc = 0;
        unordered_map<int,int> ht;

        for(const int a: num)
        {
            if(ht.find(a) == ht.end()) 
            {
                auto it1 = ht.find(a-1);
                auto it2 = ht.find(a+1);
                int len;
                if(it1 == ht.end() && it2 == ht.end())
                {
                    len = 1;
                    ht[a] = len; 
                }
                else if(it1 == ht.end())
                {
                    len = it2->second+1; 
                    ht[a] = len;
                    ht[a+len-1] = len;
                }
                else if(it2 == ht.end())
                {
                    len = it1->second+1; 
                    ht[a] = len;
                    ht[a-len+1] = len;
                }
                else
                {
                    len = it1->second+it2->second+1; 
                    ht[a-it1->second] = len;
                    ht[a+it2->second] = len;
                    ht[a] = len;
                }
                if(len>lc)
                    lc = len;
            }
        }

        return lc;
    }
};
