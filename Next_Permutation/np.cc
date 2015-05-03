class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size()<2)        
            return;

        int i = num.size()-1;
        while((i-1)>=0 && num[i-1]>=num[i])
            i--;

        if(i == 0)
        {
            reverse(num.begin(),num.end()); 
            return;
        }

        int j = num.size()-1;
        while(num[j]<=num[i-1])
            j--;

        int temp = num[i-1];
        num[i-1] = num[j];
        num[j] = temp;

        reverse(num.begin()+i, num.end());

        return;
    }
};
