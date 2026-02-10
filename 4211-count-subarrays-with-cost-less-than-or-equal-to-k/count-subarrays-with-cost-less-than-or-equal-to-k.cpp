class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<int>st;
        long long ans=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            long long cost=1LL*(*prev(st.end())-(*st.begin()))*(i-l+1);
            while(cost>k){
                st.erase(st.find(nums[l]));
                l++;
                cost=1LL*(*prev(st.end())-(*st.begin()))*(i-l+1);
            }
            ans+=(i-l+1);

        }
        return ans;
    }
};