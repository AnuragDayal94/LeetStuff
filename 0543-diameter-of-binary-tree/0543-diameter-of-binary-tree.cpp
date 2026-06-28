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

    int solve(TreeNode* root){
        if(root==NULL)return 0;

        return max(1+solve(root->left),1+solve(root->right)) ;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;

        int ans=solve(root->left) + solve(root->right);
        cout<<ans<<endl;
        ans=max(ans,diameterOfBinaryTree(root->left));
        cout<<ans<<endl;

        ans=max(ans,diameterOfBinaryTree(root->right));
        cout<<ans<<endl;

        return ans;

    }
};