class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // assume matrix is not empty
        int nRows = matrix.size();
        int nCols = matrix[0].size();

        int maxr = 0;

        int row, col;
        for(row = 0; row < nRows; row++)
            for(col = 0; col < nCols; col++)
            {
                if(matrix[row][col] == '1')
                {
                    int right = nCols; 
                    int curr_row = row; 
                    while( curr_row < nRows && matrix[curr_row][col] == '1')
                    {
                        int curr_col = col;
                        while(curr_col<right && matrix[curr_row][curr_col] == '1')
                            curr_col++;

                        int tempr = (curr_row-row+1)*(curr_col-col);
                        if(tempr > maxr)
                            maxr = tempr;

                        if(curr_col<right)
                            right = curr_col;
                        curr_row++; 
                    }
                }
            }
        return maxr;
    }
};
