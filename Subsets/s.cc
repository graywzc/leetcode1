// iterative method
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;            
        vector<int> temp;
        res.push_back(temp);

        if(!S.empty()) sort(S.begin(), S.end());

        for(const int& a: S)
        {
            int size = res.size();
            for(int i = 0; i <size; i++)     
            {
                vector<int> nu(res[i]); 
                nu.push_back(a);
                res.push_back(nu);
            }
        }

        return res;
    }
};
