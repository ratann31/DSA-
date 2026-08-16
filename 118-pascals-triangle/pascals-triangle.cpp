class Solution {
public:
    vector<int>ithRow(int rowNo){
        long long ans=1;
        vector<int>temp;
        temp.push_back(1);

        for(int i=1;i<=rowNo;i++){
            ans=ans*(rowNo-i+1);
            ans=ans/i;
            temp.push_back(ans);

        }
        return temp;

    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            ans.push_back(ithRow(i));
        }
        return ans;
    }
};