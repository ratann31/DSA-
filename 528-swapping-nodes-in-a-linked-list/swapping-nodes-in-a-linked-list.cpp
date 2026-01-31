/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>temp;
        ListNode* curr=head;
        while(curr!=NULL){
            temp.push_back(curr->val);
            curr=curr->next;
        }
        int n=temp.size();
        swap(temp[k-1],temp[n-k]);
        ListNode* newHead=new ListNode(temp[0],NULL);
        curr=newHead;
        for(int i=1;i<n;i++){
            int nodeVal=temp[i];
            ListNode* newNode=new ListNode(nodeVal,NULL);
            curr->next=newNode;
            curr=curr->next;
        }
        return newHead;
    }
};