class Solution {
public:
    int search(int A[], int n, int target) {
        if(n<=0)    
            return -1;

        int start = 0;
        int end = n-1;
        
        while(start<=end)
        {
            int mid = (start+end)/2; 

            if(A[mid] == target)
                return mid;
            if(A[mid]>=A[start])
            {
                if(target<A[mid] && target>=A[start]) 
                    end = mid-1;
                else
                    start = mid+1;
            }
            else
            {
                if(target>A[mid] && target<= A[end]) 
                    start = mid+1;
                else
                    end = mid-1;
            }
        }

        return -1;
    }
};
