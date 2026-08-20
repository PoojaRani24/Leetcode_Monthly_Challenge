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
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *dummy=new ListNode(102);
        dummy->next=head;
        ListNode *curr = head, *prev=dummy;
        while(curr){
            while(curr && curr->val==prev->val){
                curr=curr->next;
            }
            prev->next=curr;
            prev=curr;
            if(curr)
                curr=curr->next;
        }
        return dummy->next;
    }
};