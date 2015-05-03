class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;        
        vector<int> temp;
        res.push_back(temp);

        if(!S.empty()) sort(S.begin(), S.end());

        int i = 0;
        while(i < S.size())
        {
            int val = S[i]; 
            int count = 1;
            while((i+count)<S.size() && S[i+count] == val)
                count++;
            
            int size = res.size();
            for(int j = 0; j < size; j++)
            {
                vector<int> nu(res[j]); 
                int k = count;
                while(k>0)
                {
                    nu.push_back(val);
                    res.push_back(nu);
                    k--; 
                }
            }
            i = i+count;
        }

        return res;
    }
};
