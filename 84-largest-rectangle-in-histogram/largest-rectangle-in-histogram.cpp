class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        // left[i]  = index of nearest smaller element on LEFT
        // right[i] = index of nearest smaller element on RIGHT
        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;


        // =========================================================
        // STEP 1: Find Nearest Smaller Element on RIGHT
        // =========================================================

        for(int i = n - 1; i >= 0; i--) {

            // Remove all elements which are >= current height
            // because we need a STRICTLY smaller element
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // No smaller element on right
            // So rectangle can extend till the end of array
            if(st.empty()) {
                right[i] = n;
            }
            else {
                // Top is the nearest smaller element on right
                right[i] = st.top();
            }

            // Store current index in stack
            st.push(i);
        }


        // Empty the stack before finding left
        while(!st.empty()) {
            st.pop();
        }


        // =========================================================
        // STEP 2: Find Nearest Smaller Element on LEFT
        // =========================================================

        for(int i = 0; i < n; i++) {

            // Remove elements >= current height
            // because we need a STRICTLY smaller element
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // No smaller element on left
            // So rectangle can extend till beginning
            if(st.empty()) {
                left[i] = -1;
            }
            else {
                // Top is nearest smaller element on left
                left[i] = st.top();
            }

            // Store current index
            st.push(i);
        }


        // =========================================================
        // STEP 3: Calculate Maximum Rectangle
        // =========================================================

        int ans = 0;

        for(int i = 0; i < n; i++) {

            // Example:
            //
            // left  = 1
            // right = 4
            //
            // Indices 2 and 3 are available
            //
            // width = 4 - 1 - 1 = 2
            int width = right[i] - left[i] - 1;

            // Current bar is the smallest height
            // throughout this width
            int area = heights[i] * width;

            // Keep maximum rectangle
            ans = max(ans, area);
        }

        return ans;
    }
};