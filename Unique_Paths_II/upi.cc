class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        assert(obstacleGrid.size());        

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> up(n,0);
        int first = obstacleGrid[0][0]?0:1;
        for(int i = 0; i < m; i++)
        {
            first = obstacleGrid[i][0]?0:first;
            up[0] = first;

            for(int j = 1; j < n; j++)
                up[j] = obstacleGrid[i][j]?0:(up[j] + up[j-1]);
        }

        return up[n-1];
    }
};
