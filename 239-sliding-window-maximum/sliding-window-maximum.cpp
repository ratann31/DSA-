class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        1.create a max heap
        2.put only top k max element in the heap
        3.top element at the last will be the ans
        */
        int n=nums.size();
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<n;i++){
            pq.push({nums[i],i});
            while(pq.top().second<=i-k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};