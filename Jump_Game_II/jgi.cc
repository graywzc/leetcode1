class Solution {
public:
    int jump(int A[], int n) {
        if(n<2) return 0;        

        int far_reach = 0;
        int cur = 0;
        int jump = 0;
        while(cur<=far_reach)
        {
            int next_reach = far_reach;
            while(cur<=far_reach) 
            {
                if((cur+A[cur])>next_reach)
                    next_reach = cur+A[cur];
                cur++; 
            }

            jump++;
            if(next_reach>=n-1)
                return jump;

            far_reach = next_reach;
        }

        return -1;
    }
};
