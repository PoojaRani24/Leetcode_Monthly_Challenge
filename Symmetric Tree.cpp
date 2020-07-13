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
    bool check(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL)
            return true;
        else if((p!=NULL && q==NULL) || (p==NULL && q!=NULL))
            return false;
        else
            return (check(p->left,q->right) && p->val==q->val && check(p->right,q->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;
       return check(root->left,root->right);
    }
};
