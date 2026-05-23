class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>>ans;
        int idx=n;
        for(int i=0;i<n;i++){
            //case-1
            if(intervals[i][1]<newInterval[0]){
                ans.push_back(intervals[i]);
            }else if(intervals[i][0]>newInterval[1]){//case-2
               idx=i;
               break;
            }else{
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
        }
        ans.push_back(newInterval);
        for(int i=idx;i<n;i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};