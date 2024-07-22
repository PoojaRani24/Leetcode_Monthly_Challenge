/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    long di=0;
    int diameter(Node* root) {
        maxHeight(root);
        return di;
    }

    int maxHeight(Node* root){
        if(root==NULL)
            return 0;
        long maxH1=0, maxH2=0;
        for(int i=0;i<root->children.size();i++){
            int height = maxHeight(root->children[i]);
            cout<<height<<" "<<root->children[i]->val<<endl;
            if(height>maxH1){
                maxH2=maxH1;
                maxH1=height;
            }
            else if(height>maxH2)
                maxH2=height;
        }
        cout<<root->val<<" "<<maxH1<<" "<<maxH2<<endl;
        di=max(di, maxH1+maxH2);
        return 1+max(maxH1,maxH2);
    }
};