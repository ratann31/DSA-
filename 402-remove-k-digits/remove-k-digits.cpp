class Solution {
public:
    string removeKdigits(string num, int k) {

        // Stack will store the digits that we decide to keep.
        // We maintain the digits in increasing order as much as possible.
        stack<char> st;


        // =========================================================
        // STEP 1: Traverse every digit
        // =========================================================

        for(int i = 0; i < num.size(); i++) {

            // If:
            // 1. Stack is not empty
            // 2. We still have digits available to remove (k > 0)
            // 3. Top digit is greater than current digit
            //
            // Then removing the bigger top digit will make
            // the final number smaller.
            //
            // Example:
            // stack = 143
            // current digit = 2
            //
            // Remove 3 because 142 is smaller than 1432.
            while(!st.empty() &&
                  k > 0 &&
                  (st.top() - '0') > (num[i] - '0')) {

                st.pop();
                k--;
            }

            // Keep the current digit
            st.push(num[i]);
        }


        // =========================================================
        // STEP 2: If k is still remaining
        // =========================================================
        //
        // This happens when the number is already in increasing
        // order, for example:
        //
        // num = "12345", k = 2
        //
        // No digit was removed in the above loop.
        //
        // To make the number smallest, remove digits from the END.
        while(k > 0) {
            st.pop();
            k--;
        }


        // If nothing is left in stack,
        // the answer is 0.
        if(st.empty()) {
            return "0";
        }


        // =========================================================
        // STEP 3: Convert stack into string
        // =========================================================
        //
        // Stack gives elements in reverse order.
        //
        // Example:
        // stack: 1 2 3
        //
        // popping gives: 3 2 1
        //
        // So we will reverse the result later.

        string res = "";

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }


        // =========================================================
        // STEP 4: Remove leading zeros
        // =========================================================
        //
        // Because we built the string in reverse,
        // leading zeros are currently at the BACK.
        //
        // Example:
        // Actual answer = "00123"
        //
        // res before reverse = "32100"
        //
        // Remove zeros from back:
        // "321"
        //
        // After reverse:
        // "123"

        while(res.size() != 0 && res.back() == '0') {
            res.pop_back();
        }


        // Reverse because stack gave us the digits backwards.
        reverse(res.begin(), res.end());


        // If only zeros were present,
        // return "0" instead of an empty string.
        if(res.empty()) {
            return "0";
        }

        return res;
    }
};