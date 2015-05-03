class Solution {
public:

    int fsmsa(int A[], int m, int B[], int n)
    {
        assert((m+n)%2 == 1);
        if(m>n)
        {
            int* temp = A; 
            A = B;
            B = temp;
            int l = m;
            m = n;
            n = l;
        }

        int starta = 0;
        int enda = m-1;
        int startb = (n-m-1)/2;
        int endb = (n+m-1)/2;

        while(starta<=enda)
        {
            int i = (starta+enda)/2;             
            int j = (m+n-1)/2 - i;
            if(B[j-1]<=A[i] && A[i]<=B[j])
                return A[i];
            else if(A[i]<B[j-1])
            {
                starta = i+1; 
                endb = j-1;
            }
            else
            {
                enda = i-1; 
                startb = j;
            }
        }

        assert(startb==endb);
        return B[startb];
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {

        assert(m>0 || n>0);
        if(((m+n)%2) == 1)
        {
            if(m<n)         
                return fsmsa(A,m,B,n);
            else
                return fsmsa(B,n,A,m);
        }
        else
        {
            if(m==0)
                return (double)(B[n/2]+B[n/2-1])/2;
            if(n==0)
                return (double)(A[m/2]+A[m/2-1])/2;
            double m1,m2;
            if(A[0]<=B[0]) 
                m1 = fsmsa(A+1,m-1,B,n);
            else
                m1 = fsmsa(A,m,B+1,n-1);

            if(A[m-1]>=B[n-1])
                m2 = fsmsa(A,m-1,B,n);
            else
                m2 = fsmsa(A,m,B,n-1);

            return (m1+m2)/2; 
        }
    }
};
