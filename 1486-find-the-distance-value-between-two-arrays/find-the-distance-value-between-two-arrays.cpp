class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1=arr1.size();
        int n2=arr2.size();

        int ans=0;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<n1;i++){
            int curr=arr1[i];
            int cnt=0;
            for(int j=0;j<n2;j++){
                int diff=abs(curr-arr2[j]);
                if(diff>d){
                    cnt++;
                }
            }
            if(cnt==n2){
                ans++;
            }
        }

        return ans;
    }
};