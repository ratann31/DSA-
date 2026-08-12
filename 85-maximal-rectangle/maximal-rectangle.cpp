class Solution {
public:

    // =========================================================
    // This function finds the largest rectangle in a histogram
    // We already know this problem.
    // =========================================================

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        // left[i]  = nearest smaller element on LEFT
        // right[i] = nearest smaller element on RIGHT
        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;


        // =====================================================
        // STEP 1: Find nearest smaller element on RIGHT
        // =====================================================

        for(int i = n - 1; i >= 0; i--) {

            // Remove elements greater than or equal to
            // current height.
            //
            // We need a STRICTLY smaller element.
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // No smaller element on right
            // Rectangle can extend till the end.
            if(st.empty()) {
                right[i] = n;
            }
            else {
                right[i] = st.top();
            }

            st.push(i);
        }


        // Clear stack before finding left
        while(!st.empty()) {
            st.pop();
        }


        // =====================================================
        // STEP 2: Find nearest smaller element on LEFT
        // =====================================================

        for(int i = 0; i < n; i++) {

            // Remove elements >= current height
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // No smaller element on left
            // Rectangle can extend till beginning.
            if(st.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = st.top();
            }

            st.push(i);
        }


        // =====================================================
        // STEP 3: Calculate maximum rectangle
        // =====================================================

        int ans = 0;

        for(int i = 0; i < n; i++) {

            // Width available for current height
            int width = right[i] - left[i] - 1;

            // Area = height × width
            int area = heights[i] * width;

            ans = max(ans, area);
        }

        return ans;
    }


    // =========================================================
    // MAXIMAL RECTANGLE
    // =========================================================

    int maximalRectangle(vector<vector<char>>& matrix) {

        // Empty matrix
        if(matrix.empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        // heights[j] tells us:
        //
        // How many consecutive 1s are present
        // vertically at column j.
        //
        // Initially there are no rows processed,
        // so all heights are 0.
        vector<int> heights(cols, 0);

        int ans = 0;


        // =====================================================
        // STEP 1: Process matrix row by row
        // =====================================================

        for(int i = 0; i < rows; i++) {

            // Update histogram heights for current row
            for(int j = 0; j < cols; j++) {

                if(matrix[i][j] == '1') {

                    // Current cell is 1,
                    // so increase height.
                    heights[j]++;
                }
                else {

                    // Current cell is 0,
                    // so consecutive 1s break.
                    heights[j] = 0;
                }
            }


            // =================================================
            // STEP 2:
            // Treat current row as a histogram
            // and find largest rectangle.
            // =================================================

            int currentArea = largestRectangleArea(heights);


            // =================================================
            // STEP 3:
            // Keep maximum answer.
            // =================================================

            ans = max(ans, currentArea);
        }


        // =====================================================
        // STEP 4: Return maximum rectangle found
        // =====================================================

        return ans;
    }
};