class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
        }
        vector<int>ans(2*n);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=v[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }else{
                ans[i]=st.top();
            }
            st.push(v[i]);
        }
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i]=ans[i];
        }
        return res;
    }
};