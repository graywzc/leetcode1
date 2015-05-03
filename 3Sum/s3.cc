class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size()<3)
            return res;

        sort(num.begin(), num.end());        

        for(int i = 0; i<=num.size()-3; i++)
        {
            if(i!=0&&num[i]==num[i-1])
                continue;

            int sum = -num[i]; 
            int j = i+1; 
            int k = num.size()-1;
            while(j<k)
            {
                if((num[j]+num[k]) == sum) 
                {
                    vector<int> temp = {num[i], num[j], num[k]};
                    res.push_back(temp);

                    do{j++;} while(num[j] == num[j-1]);
                    do{k--;} while(num[k] == num[k+1]);
                }
                else if((num[j]+num[k])>sum)
                {
                    k--; 
                }
                else
                {
                    j++; 
                }
            }
        }

        return res;
    }
};
