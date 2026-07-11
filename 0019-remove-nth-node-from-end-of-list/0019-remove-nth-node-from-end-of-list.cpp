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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp=head;
        int c=0;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        temp=head;
        n=c-n;
        if(n==0){
            head=head->next;
            return head;
        }
        c=0;
        while(c<n-1){
            c++;
            temp=temp->next;
        }
        if(temp==NULL||temp->next==NULL) return nullptr;
        else if(temp->next->next==NULL) temp->next=NULL;
        else temp->next=temp->next->next;
        return head;
    }
};