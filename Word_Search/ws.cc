class Solution {
public:

    bool exist(vector<vector<char> > &board, int pos_x, int pos_y, const string& word, int idx)
    {
        if(word[idx] != board[pos_x][pos_y]) 
            return false;
        else if(idx == word.size()-1)
            return true;
        else
        {
            char temp = board[pos_x][pos_y];
            board[pos_x][pos_y] = '\0';
            if(pos_x>0 && exist(board, pos_x-1, pos_y, word, idx+1))
                return true;

            if(pos_x<(board.size()-1) && exist(board, pos_x+1, pos_y, word, idx+1))
                return true;

            if(pos_y>0 && exist(board, pos_x, pos_y-1, word, idx+1))
                return true;

            if(pos_y<(board[0].size()-1) && exist(board, pos_x, pos_y+1, word, idx+1))
                return true;
            board[pos_x][pos_y] = temp;
            return false;
        }
    }

    bool exist(vector<vector<char> > &board, string word) {

        if(word.empty())
            return true;

        if(board.empty())                
            return false;

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(exist(board, i, j, word, 0)) 
                    return true;

        return false;
    }
};
