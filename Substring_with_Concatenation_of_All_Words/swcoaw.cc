class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if(S.empty() || L.empty() || L[0].empty() )        
            return res;

        int size = S.size();
        int wl = L[0].size();
        int num = L.size();
        
        if(size<(wl*L.size()))
            return res;

        unordered_map<string,int> dict;
        vector<int> appear;
        for(string l: L)
        {
            if(dict.find(l)==dict.end())
            {
                dict[l] = appear.size();
                appear.push_back(1);
            }
            else
                appear[dict[l]]++; 
        }

        vector<int> match(size, -1);
        int i = 0;
        while((i+wl)<=size)
        {
            if(dict.find(S.substr(i,wl)) != dict.end()) 
                match[i] = dict[S.substr(i,wl)];
            i++; 
        }

        i = 0;
        while((i+wl*num)<=size)
        {
            vector<int> temp(appear.size(),0);
            int j = 0;
            while(j<num)
            {
                int idx = match[i+j*wl];
                if(idx==-1 || temp[idx] == appear[idx]) 
                    break;

                temp[idx] ++; 
                j++; 
            }

            if(j==num)
                res.push_back(i);
            i++; 
        }
        return res;
    }
};
