class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k=j+1;
                int l=n-1;

                while(k<l){
                    long long  currSum=1LL*nums[i]+nums[j]+nums[k]+nums[l];

                    if(currSum == target){
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};

                        st.insert(temp);
                        k++;
                        l--;
                    }else if(currSum < target){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
    }
};