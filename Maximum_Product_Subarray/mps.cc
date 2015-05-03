class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxp = INT_MIN;        
        int maxpos = 0;
        int maxneg = 0;

        int i = 0;
        while(i<n)
        {
            if(A[i] == 0)
            {
                maxpos = 0; 
                maxneg = 0;

                if(maxp < 0)
                    maxp = 0;
            }
            else if(A[i] > 0)
            {
                maxpos = (maxpos>0)?maxpos*A[i]:A[i]; 
                maxneg = (maxneg<0)?maxneg*A[i]:0;

                if(maxpos!=0)
                {
                    if(maxpos > maxp)
                        maxp = maxpos;
                }
                else
                {
                    if(maxneg!=0 && maxneg>maxp) 
                        maxp = maxneg;
                }
            }
            else
            {
                int temp = maxneg;
                maxneg = (maxpos==0)?A[i]:A[i]*maxpos; 
                maxpos = (temp==0)?0:temp * A[i];

                if(maxpos!=0)
                {
                    if(maxpos > maxp)
                        maxp = maxpos;
                }
                else
                {
                    if(maxneg!=0 && maxneg>maxp) 
                        maxp = maxneg;
                }
            }
            i++; 
        }

        return maxp;
    }
};
