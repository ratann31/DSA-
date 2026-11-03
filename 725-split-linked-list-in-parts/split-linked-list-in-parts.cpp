class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* curr=head;

        while(curr!=NULL){
            n++;
            curr=curr->next;
        }

        int rem=n%k;
        int div=n/k;

        vector<ListNode*>ans;
        curr=head;

        int currSize=div;
        int cnt=0;
        ListNode* currHead=head;
        while(ans.size()<k){
            currSize=div;
            if(rem>0){
                currSize+=1;
                rem-=1;
            }
            cnt=0;
            currHead=curr;

            while(cnt<currSize && curr!=NULL){
                cnt++;
                if(cnt==currSize){
                    ListNode* temp=curr->next;
                    curr->next=NULL;
                    curr=temp;
                    break;
                }
                curr=curr->next;
            }

            ans.push_back(currHead);
        }

        return ans;
    }
};