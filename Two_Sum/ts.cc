class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_map<int, int> hm;        
        for(int i = 0; i < numbers.size(); i++)
        {
            int num = numbers[i];         
            auto it = hm.find(num);
            if(it != hm.end())
            {
                res.push_back(hm[num]); 
                res.push_back(i+1);
                return res;
            }
            else
            {
                if(hm.find(target-num)==hm.end())
                    hm[target-num] = i+1;
            }
        }

        return res;
    }
};
