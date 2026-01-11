class Solution {
public:
   int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int width = n - left - 1;
            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();//row
        int m=matrix[0].size();//col
        
        int maxArea=0;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            int area=largestRectangleArea(height);
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};