class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())            
            return 0;
        if(triangle.size() == 1)
            return triangle[0][0];
        int i = triangle.size()-2;
        while(i>=0)
        {
            int j = 0;
            while(j<=i)
            {
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
                j++; 
            }
            i--; 
        }

        return triangle[0][0];
    }
};
