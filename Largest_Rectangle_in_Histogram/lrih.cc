class Solution {
public:
    int largestRectangleArea(vector<int> &height) {

        stack<int> st;
        int i = 0;
        int lra = 0;
        while(i < height.size() || !st.empty())
        {
            while(!st.empty() && (i==height.size() || height[st.top()]>height[i]))
            {
                int h = height[st.top()];
                st.pop();
                int left = st.empty()?-1:st.top();
                int ra = (i-left-1)*h;
                if(ra>lra) lra = ra;
            }


            if(i < height.size() && (st.empty() || height[st.top()]<=height[i]))
                st.push(i);

            i++; 
        }

        return lra;
    }
};
