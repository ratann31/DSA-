class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++){
            if(st.empty() || nums[i]>*st.rbegin()){
                st.insert(nums[i]);
            }else{
                auto it=st.lower_bound(nums[i]);
                st.erase(*it);
                st.insert(nums[i]);
            }
        }
        return st.size();
    }
};