class Solution {
public:

    // =========================================================
    // Find Sum of All Subarray Maximums
    // =========================================================
    long long subarrayMax(vector<int>& arr) {

        int n = arr.size();

        // nge[i] = Next Greater Element index
        vector<int> nge(n);

        // pgee[i] = Previous Greater OR Equal Element index
        vector<int> pgee(n);

        stack<int> st;


        // ---------------------------------------------------------
        // Find Next Greater Element
        // ---------------------------------------------------------
        for(int i = n - 1; i >= 0; i--) {

            // Remove elements smaller than or equal to current
            // because we need a STRICTLY greater element
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                // No greater element on right
                nge[i] = n;
            }
            else {
                nge[i] = st.top();
            }

            st.push(i);
        }


        // Clear stack
        while(!st.empty()) {
            st.pop();
        }


        // ---------------------------------------------------------
        // Find Previous Greater OR Equal Element
        // ---------------------------------------------------------
        for(int i = 0; i < n; i++) {

            // Remove strictly smaller elements
            // Equal elements are allowed to stay
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                // No greater/equal element on left
                pgee[i] = -1;
            }
            else {
                pgee[i] = st.top();
            }

            st.push(i);
        }


        // ---------------------------------------------------------
        // Calculate contribution of every element
        // ---------------------------------------------------------
        long long sum = 0;

        for(int i = 0; i < n; i++) {

            // Number of choices for left boundary
            int left = i - pgee[i];

            // Number of choices for right boundary
            int right = nge[i] - i;

            // Number of subarrays where arr[i] is maximum
            long long frequency = 1LL * left * right;

            // Contribution of arr[i]
            sum += frequency * arr[i];
        }

        return sum;
    }


    // =========================================================
    // Find Sum of All Subarray Minimums
    // =========================================================
    long long subarrayMin(vector<int>& arr) {

        int n = arr.size();

        // nse[i] = Next Smaller Element index
        vector<int> nse(n);

        // psee[i] = Previous Smaller OR Equal Element index
        vector<int> psee(n);

        stack<int> st;


        // ---------------------------------------------------------
        // Find Next Smaller Element
        // ---------------------------------------------------------
        for(int i = n - 1; i >= 0; i--) {

            // Remove elements greater than or equal to current
            // because we need a STRICTLY smaller element
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                // No smaller element on right
                nse[i] = n;
            }
            else {
                nse[i] = st.top();
            }

            st.push(i);
        }


        // Clear stack
        while(!st.empty()) {
            st.pop();
        }


        // ---------------------------------------------------------
        // Find Previous Smaller OR Equal Element
        // ---------------------------------------------------------
        for(int i = 0; i < n; i++) {

            // Remove strictly greater elements
            // Equal elements are allowed to stay
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                // No smaller/equal element on left
                psee[i] = -1;
            }
            else {
                psee[i] = st.top();
            }

            st.push(i);
        }


        // ---------------------------------------------------------
        // Calculate contribution of every element
        // ---------------------------------------------------------
        long long sum = 0;

        for(int i = 0; i < n; i++) {

            // Number of choices for left boundary
            int left = i - psee[i];

            // Number of choices for right boundary
            int right = nse[i] - i;

            // Number of subarrays where arr[i] is minimum
            long long frequency = 1LL * left * right;

            // Contribution of arr[i]
            sum += frequency * arr[i];
        }

        return sum;
    }


    // =========================================================
    // MAIN FUNCTION
    // =========================================================
    long long subArrayRanges(vector<int>& nums) {

        // Range of a subarray =
        // maximum - minimum
        //
        // Therefore:
        //
        // Sum of ranges =
        // Sum of all maximums - Sum of all minimums

        return subarrayMax(nums) - subarrayMin(nums);
    }
};