class Solution {
public:
    void recursiveCS2(vector<int> &num, int idx, vector<int> &temp, int target, vector<vector<int> > &res)
    {
        // target is  positive
        if(idx == num.size())
            return;
        else
        {
            int cand = num[idx]; 
            if(target >= cand)
            {
                int count = 1;         
                while((idx+count)<num.size() && num[idx+count] == num[idx])
                {
                    count++; 
                }

                int i = count;
                int next_target = target; 
                while(next_target>0 && i>=0)
                {
                    recursiveCS2(num,idx+count,temp,next_target,res); 
                    next_target-=cand;
                    temp.push_back(cand);
                    i--;
                    if(next_target == 0 && i>=0)
                    {
                        res.push_back(temp); 
                    }
                }

                while(count>i)
                {
                    temp.pop_back(); 
                    count--;
                }
            }
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        
        if(num.empty())
            return res;
        
        sort(num.begin(), num.end());
        vector<int> temp;
        recursiveCS2(num, 0, temp, target, res);
        return res;
    }
};
