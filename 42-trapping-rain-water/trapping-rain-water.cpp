class Solution {
public:
    int trap(vector<int>& height) {
        /*
        1.find left max and right max for each arr[i]
        2.for each arr[i]....water trapped will be : min(leftmax[i],rightmax[i])-arr[i]
        3.ans=sum of all water trapped
        */
        int n=height.size();
        int l=INT_MIN;
        vector<int>lmax(n,0);
        for(int i=0;i<n;i++){
            lmax[i]=max(l,height[i]);
            l=max(l,height[i]);
        }
        int r=INT_MIN;
        vector<int>rmax(n,0);
        for(int i=n-1;i>=0;i--){
            rmax[i]=max(r,height[i]);
            r=max(r,height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
           ans+=max(0,min(lmax[i],rmax[i])-height[i]);
        }
        return ans;
    }
};