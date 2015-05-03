class Solution {
public:
    int trap(int A[], int n) {
        if(n<3)        
            return 0;
        vector<int> hb(n,0);
        int high = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i]>=high) 
                high = A[i];
            else
                hb[i] = high - A[i];
        }

        high = 0;
        int trap = 0;
        for(int i = n-1; i > 0; i--)
        {
            if(A[i]>=high)     
                high = A[i];
            else
                trap += min(high-A[i],hb[i]); 
        }

        return trap;
    }
};
