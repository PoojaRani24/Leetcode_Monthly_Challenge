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
    int ans=INT_MIN;
public:
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        int left_height=height(root->left);
        int right_height=height(root->right);
        ans=max(ans,(left_height+right_height+1));
        return (max(left_height,right_height)+1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        height(root);
        return ans-1;
    }
};
