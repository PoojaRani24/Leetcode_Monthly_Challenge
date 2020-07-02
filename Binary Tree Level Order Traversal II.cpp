/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
            return v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        while(q.size()>1){
            TreeNode* p=q.front();
            if(p!=NULL){
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                temp.push_back(p->val);
                q.pop();
            }
            else{
                q.pop();
                q.push(NULL);
                v.insert(v.begin(),temp);
                temp.clear();
            }
        }
        v.insert(v.begin(),temp);
        return v;
    }
};
