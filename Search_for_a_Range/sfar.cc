class Solution {
public:

    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        if(n == 0) 
            return res;

        // search for the left
        int start = 0;
        int end = n-1;
        while(start<end)
        {
            int mid = (start+end)/2; 
            if(A[mid] == target)
                end = mid;
            else if(A[mid]>target)
                end = mid-1;
            else
                start = mid+1;
        }
        if(start != end || A[start] != target)
            return res;

        res[0] = start;
        end = n-1;
        while(start<end)
        {
            int mid = (start+end+1)/2; 
            if(A[mid] == target)
                start = mid;
            else if(A[mid]>target)
                end = mid-1;
            else
                start = mid+1;
        }
        assert(start==end);
        res[1] = start;
        
        return res;
    }
};
