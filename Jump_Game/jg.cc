class Solution {
public:
    bool canJump(int A[], int n) {
        if(n<2) return true;
        int far_reach = 0;        
        int cur = 0;
        while(cur<=far_reach)
        {
            if(cur+A[cur] > far_reach) 
                far_reach = cur+A[cur];

            if(far_reach>=n-1)
                return true;
            cur++;
        }

        return false;
    }
};
