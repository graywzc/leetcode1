class Solution {
public:
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    int firstMissingPositive(int A[], int n) {
        // firstly move negative intergers and 0 to the right of the array        
        int count = n;
        int i = 0;
        while(i < count)
        {
            if(A[i]<=0)    
            {
                swap(A[i], A[count-1]);
                count--;
            }
            else
                i++;
        }

        i = 0;
        while(i < count)
        {
            if((abs(A[i])-1)<count && A[abs(A[i])-1] > 0)
                A[abs(A[i])-1] *= -1; 
            i++; 
        }

        i = 0;
        while(i < count)
        {
            if(A[i]>0)
                return i+1;
            i++; 
        }

        return i+1;
    }
};
