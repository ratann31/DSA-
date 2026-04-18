class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int a=0,b=0;
        int target=0;
        for(auto it:nums) target^=it;

        // b=target;
        // 7
        // 111

        for(int bit=31;bit>=0;bit--){
            if((1<<bit) &target){
                for(int i=0;i<n;i++){
                    if(nums[i] &(1<<bit)) a^=nums[i];
                    else b^=nums[i];
                }

                break;
            }
            
        }
        cout<<a<<" "<<b<<endl;
        ans.push_back(a);
        ans.push_back(b);
        return ans;

    }
};