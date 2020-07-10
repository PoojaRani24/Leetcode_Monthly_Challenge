/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flat(Node* temp){
        if(temp->next==NULL && temp->child)
        {
            temp->next=temp->child;
            temp->child->prev=temp;
            temp->child=NULL;
            flat(temp->next);
            return temp;
        }
        while(temp->next!=NULL){
            if(temp->child){
                Node* ptr=temp->next;
                temp->next=temp->child;
                temp->child=NULL;
                temp->next->prev=temp;
                Node* p=flat(temp->next);
                p->next=ptr;
                ptr->prev=p;
                temp=ptr;
            }
            else{
                temp=temp->next;
            }
        }
        return temp;
    }
    
    Node* flatten(Node* head) {
        if(head==NULL)
            return NULL;
        else if(head->next==NULL && head->child)
        {
            head->next=head->child;
            head->child->prev=head;
            head->child=NULL;
            Node* p=flat(head->next);
            //p->next=head;
            return head;
        }
        Node* p=flat(head);
        p->next=NULL;
       return head;
    }
};
