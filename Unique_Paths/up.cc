class Solution {
public:
    int uniquePaths(int m, int n) {
        assert(m>0 && n>0);

        vector<int> pn(n,0);
        pn[0] = 1;
        
        while(m>0)
        {
            int i = 1;
            while(i<n)
            {
                pn[i] += pn[i-1];
                i++; 
            }
            m--; 
        }
        return pn[n-1];
    }
};
