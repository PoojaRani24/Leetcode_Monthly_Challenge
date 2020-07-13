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
    bool sumfound(TreeNode* root, int sumsofar,int target){
        if(root==NULL)
            return false;
        sumsofar+=root->val;
       if(root->left==NULL && root->right==NULL)
            return sumsofar==target;
        else
            return (sumfound(root->left,sumsofar,target)||sumfound(root->right,sumsofar,target));
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return sumfound(root,0,sum);
    }
};
