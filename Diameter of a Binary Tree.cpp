pair<int,int> dfs(Node* root){
    if(root==NULL)
        return {0,0};
    pair<int,int> left=dfs(root->left);
    pair<int,int> right=dfs(root->right);
    int dia=max(left.first,right.first);
    dia=max(dia,(left.second+right.second));
    return {dia,max(left.second+1,right.second+1)};
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    // Your code here
    return dfs(node).first+1;
}
