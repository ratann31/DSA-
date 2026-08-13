class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        //step-1:LeftMax
        int l=INT_MIN;
        vector<int>leftMax(n,0);
        for(int i=0;i<n;i++){
            leftMax[i]=max(l,height[i]);
            l=max(l,height[i]);
        }
        //step-2:RightMax
        int r=INT_MIN;
        vector<int>rightMax(n,0);
        for(int i=n-1;i>=0;i--){
            rightMax[i]=max(r,height[i]);
            r=max(r,height[i]);
        }

        int totalTrappedWater=0;
        for(int i=0;i<n;i++){
            int minHeight = min(leftMax[i],rightMax[i]);
            totalTrappedWater += max(0,minHeight-height[i]);
        }

        return totalTrappedWater;
    }
};