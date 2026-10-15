class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s="";
        ListNode* curr=head;

        while(curr!=NULL){
            s+=curr->val + '0';
            curr=curr->next;
        }

        string temp=s;
        reverse(temp.begin(),temp.end());
        cout<<temp<<endl;
        cout<<s<<endl;
        return temp==s;
    }
};