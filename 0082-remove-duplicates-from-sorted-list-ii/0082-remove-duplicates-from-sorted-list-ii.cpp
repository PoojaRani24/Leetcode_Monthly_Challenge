class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            // Check if curr is the start of a duplicate group
            if (curr->next && curr->val == curr->next->val) {

                // Skip the entire duplicate group
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }

                // Remove the entire group
                prev->next = curr->next;
            }
            else {
                // curr is unique, so keep it
                prev = curr;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};