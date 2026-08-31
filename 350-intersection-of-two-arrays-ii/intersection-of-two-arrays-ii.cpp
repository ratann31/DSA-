class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;

        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;
        }

        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            int curr=nums2[i];

            if(mpp[curr]>0){
                ans.push_back(curr);
                mpp[curr]--;
            }
        }

        return ans;
    }
};