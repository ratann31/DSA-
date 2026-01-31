class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
       int L=0;
       ListNode* curr=head;
       while(curr!=NULL){
            L++;
            curr=curr->next;
       }
       int k1=k;
       ListNode* node1=head;
       while(k1>1){
        node1=node1->next;
        k1--;
       }
       int k2=L-k+1;
       ListNode* node2=head;
       while(k2>1){
        node2=node2->next;
        k2--;
       }
       swap(node1->val,node2->val);
       return head;
    }
};