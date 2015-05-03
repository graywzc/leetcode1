class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        assert(num.size()>=3);        

        sort(num.begin(), num.end());

        int min_diff = INT_MAX;
        int res;

        for(int i = 0; i <= num.size()-3; i++)
        {
            int j = i+1; 
            int k = num.size()-1;
            int nt = target-num[i]; 

            while(j<k)
            {
                if((num[j]+num[k]) == nt) 
                    return target;
                else if((num[j]+num[k])>nt)
                {
                    if((num[j]+num[k]-nt)<min_diff) 
                    {
                        res = num[i]+num[j]+num[k];
                        min_diff = num[j]+num[k]-nt;
                    }
                    k--;
                }
                else
                {
                    if((nt-num[j]-num[k])<min_diff) 
                    {
                        res = num[i]+num[j]+num[k];
                        min_diff = nt-num[j]-num[k];
                    }
                    j++;
                }
            }
        }

        return res;
    }
};
