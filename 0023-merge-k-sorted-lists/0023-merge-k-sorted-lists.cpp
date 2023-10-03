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

    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        int k=lists.size();

        // klogk
        for(int i=0;i<k;i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        
        ListNode* dummy=new ListNode(0);
        ListNode* last=dummy;
        // knlogk
        while(!pq.empty()){
            ListNode* tmp=pq.top();
            if(tmp->next)
                pq.push(tmp->next);
            tmp->next=NULL;
            pq.pop();
            last->next=tmp;
            last=last->next;
        }
        return dummy->next;
    }
};