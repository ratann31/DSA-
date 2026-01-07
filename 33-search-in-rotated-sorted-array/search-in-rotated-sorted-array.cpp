class Solution {
public:
    int find(vector<int>&nums){
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return r;
    }
    int bs1(vector<int>&nums,int idx,int &ans,int target){
        int l=0;
        int r=idx-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
    int bs2(vector<int>&nums,int idx,int &ans,int target){
        int l=idx;int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int idx=find(nums);
       // cout<<idx;
        int ans1=-1,ans2=-1;
        bs1(nums,idx,ans1,target);
        bs2(nums,idx,ans2,target);
        if(ans1==-1 && ans2==-1){
            return -1;
        }
        return max(ans1,ans2);
        
    }
};