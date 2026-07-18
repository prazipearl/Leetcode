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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode*dummy=head;
        int data=dummy->val;
        ListNode*temp=head->next;
        dummy->next=NULL;
        while(temp!=NULL){
            if(temp->val!=data){
                ListNode*newnode=new ListNode(temp->val);
                dummy->next=newnode;
                dummy=newnode;
                data=temp->val;
            }
            temp=temp->next;
        }
        return head;
    }
};