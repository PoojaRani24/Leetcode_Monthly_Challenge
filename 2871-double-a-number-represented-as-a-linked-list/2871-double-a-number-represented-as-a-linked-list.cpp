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

class LinkedList{
    public:
    LinkedList(){}

    ListNode* reverse(ListNode* head){
        ListNode *prev=NULL,  *curr=head, *Next=head;
        while(curr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }

    void multiply(ListNode* head){
        int carry=0;
        ListNode* curr=head, *prev=NULL;
        while(curr){
            int val=curr->val*2 + carry;
            curr->val=val%10;
            carry=val/10;
            prev=curr;
            curr=curr->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            prev->next=newNode;
        }
    }
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        LinkedList *llobj=new LinkedList();
        head = llobj->reverse(head);
        llobj->multiply(head);
        head = llobj->reverse(head);
        return head;
    }
};