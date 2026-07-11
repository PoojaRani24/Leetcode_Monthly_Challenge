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
        if(!root)
            return {};
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>tmp;
            int cnt=q.size();
            while(cnt--){
                Node* node=q.front();
                q.pop();
                tmp.push_back(node->val);
                for(Node* nodechild:node->children)
                    q.push(nodechild);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};