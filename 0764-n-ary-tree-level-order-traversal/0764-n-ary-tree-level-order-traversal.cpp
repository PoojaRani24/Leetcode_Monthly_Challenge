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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>tmp;
            while(size--){
                Node* node=q.front();
                tmp.push_back(node->val);
                q.pop();
                for(int i=0;i<node->children.size();i++){
                    if(node->children[i])
                        q.push(node->children[i]);
                }
            }
        ans.push_back(tmp);
        }
        return ans;
    }
};