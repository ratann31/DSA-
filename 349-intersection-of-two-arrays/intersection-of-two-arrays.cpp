class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int>ans;

        int l=0,r=0;
        while(l<n1 && r<n2){
            if(nums1[l]==nums2[r]){
                if(ans.empty() || nums1[l]!=ans.back()){
                    ans.push_back(nums1[l]);
                }
                l++;
                r++;
            }else if(nums1[l]<nums2[r]){
                l++;
            }else{
                r++;
            }
        }
        return ans;
    }
};