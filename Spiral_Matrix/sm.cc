class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;        
        if(matrix.empty())
            return res;

        int left = 0;
        int right = matrix[0].size() - 1;
        int up = 0;
        int down = matrix.size() - 1;

        while(left <= right && up <= down)
        {
            if(left == right && up == down)
                res.push_back(matrix[up][left]);
            else if(left == right)
            {
                for(int i = up; i <= down; i++) 
                    res.push_back(matrix[i][left]); 
            }
            else if(up == down)
            {
                for(int i = left; i <= right; i++) 
                    res.push_back(matrix[up][i]);
            }
            else
            {
                for(int i = left; i < right; i++) 
                    res.push_back(matrix[up][i]);
                for(int i = up; i < down; i++) 
                    res.push_back(matrix[i][right]);
                for(int i = right; i > left; i--) 
                    res.push_back(matrix[down][i]);
                for(int i = down; i > up; i--) 
                    res.push_back(matrix[i][left]);
            }
            left++; 
            right--;
            up++;
            down--;
        }
        return res;
    }
};
