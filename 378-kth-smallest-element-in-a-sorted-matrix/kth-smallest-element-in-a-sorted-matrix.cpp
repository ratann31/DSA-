class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int R=matrix.size();
        int C=matrix[0].size();
        priority_queue<int>pq;//max heap
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                pq.push(matrix[i][j]);
                while(!pq.empty() && pq.size()>k){
                    pq.pop();
                }
                
            }
        }
        return pq.top();
        
    }
};