class Solution {
public:
    void recursiveCS(vector<int> &candidates, int idx, vector<int> &temp, int target, vector<vector<int> > &res)
    {
        // target should be always positive
        if(idx == candidates.size()) 
        {
            return;
        }
        else
        {
            int cand = candidates[idx];
            int next_target = target;
            int count = 0;

            while(next_target>0)
            {
                recursiveCS(candidates, idx+1, temp, next_target, res);     
                next_target -= cand;
                temp.push_back(cand);
                count++;
                if(next_target==0)
                    res.push_back(temp);
            }

            while(count>0) 
            {
                temp.pop_back(); 
                count--; 
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;    
        if(candidates.empty() || target<=0)
            return res;
        
        // assume there is no duplicate numbers in candidates
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        recursiveCS(candidates, 0, temp, target, res); 
        return res;
    }
};
