class Solution {
public:
    long long ncr(int row,int col){
        long long res=1;
        for(int i=0;i<col;i++){
            res=res*(row-i);
            res=res/(i+1);
        }
        return res;
    }
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
        vector<vector<int>>ans;
        // for(int row=0;row<numRows;row++){
        //     vector<int>temp;
        //     for(int col=0;col<=row;col++){
        //         temp.push_back(ncr(row,col));
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            ans.push_back(ithRow(i));
        }
        return ans;
    }
};