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
    ListNode* partition(ListNode* head, int x) {
        ListNode *curr=head;
        ListNode *dummy=new ListNode(0);
         ListNode *dummy1=new ListNode(1);
         dummy1->next=head;
        ListNode *end=dummy;
        ListNode *prev=dummy1;
        while(curr){
            if(curr->val<x)
                {
                    prev=curr;
                    curr=curr->next;
                }
            else{
                end->next=curr;
                end=end->next;
                // prev=curr;
                curr=curr->next;
                prev->next=curr;
                end->next=NULL;
            }
        }
        prev->next=dummy->next;
        return dummy1->next;
    }
};