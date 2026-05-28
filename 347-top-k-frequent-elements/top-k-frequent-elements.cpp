class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;//{num,freq}
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto &it:mpp){
            cout<<it.first<<"->"<<it.second<<endl;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &it:mpp){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(!pq.empty() && k>0){
            auto it=pq.top();
            int freq=it.first;
            int num=it.second;

            ans.push_back(num);
            pq.pop();
            k--;
        }
        return ans;
    }

};