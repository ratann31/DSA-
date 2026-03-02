class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        vector<int>temp;
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr=head;
        while(curr!=NULL){
            temp.push_back(curr->val);
            if(curr->next==NULL)break;
            curr=curr->next->next;
        }
        curr=head->next;
        while(curr!=NULL){
            temp.push_back(curr->val);
            if(curr->next==NULL)break;
            curr=curr->next->next;
        }
        int idx=0;
        curr=head;
        while(curr!=NULL){
            curr->val=temp[idx];
            idx++;
            curr=curr->next;
        }
        return head;
    }
};