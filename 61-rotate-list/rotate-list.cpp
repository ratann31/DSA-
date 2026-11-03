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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL) return head;

        int n=0;
        ListNode* p=head;
        while(p->next!=NULL){
            n++;
            p=p->next;
        }
        n++;
        k=k%n;
        if(k==0) return head;

        int x=n-k-1;
        int count=0;
        
        ListNode* curr=head;
        while(curr!=NULL){
           
            if(count==x){
                break;
            }
            curr=curr->next;
            count++;
        }

        ListNode* newHead=curr->next;
        curr->next=NULL;
        p->next=head;
        return newHead;

    }
};