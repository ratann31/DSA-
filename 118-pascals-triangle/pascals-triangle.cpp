class Solution {
public:
    vector<int>ithRow(int rowNo){
        long long ans=1;
        vector<int>res;
        res.push_back(1);
        for(int i=1;i<=rowNo;i++){
            ans=ans*(rowNo-i+1);
            ans=ans/i;
            res.push_back(ans);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        result.push_back({1});
        for(int i=1;i<numRows;i++){
            result.push_back(ithRow(i));
        }
        return result;
    }
};