class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size()+s2.size())!=s3.size()) 
            return false;

        if(s1.empty())
            return s2==s3;
        if(s2.empty())
            return s1==s3;

        vector<vector<bool> > il(s1.size()+1,vector<bool>(s2.size()+1,false));
        int ss1 = s1.size();
        int ss2 = s2.size();
        int ss3 = s3.size();

        il[0][0]=true;
        for(int i = 1; i <= ss1; i++)
            il[i][0] = il[i-1][0] && s1[ss1-i]==s3[ss3-i];
        for(int i = 1; i <= ss2; i++)
            il[0][i] = il[0][i-1] && s2[ss2-i]==s3[ss3-i];

        for(int i = 1; i <= ss1; i++)
            for(int j = 1; j <= ss2; j++)
            {
                il[i][j] = (s1[ss1-i]==s3[ss3-i-j]&&il[i-1][j])||
                            (s2[ss2-j]==s3[ss3-i-j]&&il[i][j-1]); 
            }

        return il[ss1][ss2];
    }
};
