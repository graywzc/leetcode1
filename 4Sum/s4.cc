class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.size() < 4)
            return res;
        sort(num.begin(), num.end());        

        for(int i = 0; i < num.size()-3; i++)
        {
            for(int j = i+1; j < (num.size()-2); j++) 
            {
                int k = j+1; 
                int l = num.size()-1;
                int temp = target - num[i] - num[j]; 
                while(k<l)
                {
                    if((num[k]+num[l])==temp)     
                    {
                        vector<int> oneres; 
                        oneres.push_back(num[i]);
                        oneres.push_back(num[j]);
                        oneres.push_back(num[k]);
                        oneres.push_back(num[l]);
                        res.push_back(oneres);
                        do{k++;}while(k<l && num[k]==num[k-1]);
                        do{l--;}while(l>k && num[l]==num[l+1]);
                    }
                    else if((num[k]+num[l])>temp)     
                    {
                        l--; 
                    }
                    else
                    {
                        k++; 
                    }
                }

                while((j+1)<num.size() && num[j] == num[j+1])
                    j++;
            }

            while((i+1)<num.size() && num[i] == num[i+1])
                i++;
        }

        return res;
    }
};
