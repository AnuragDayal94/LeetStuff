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

    int left(TreeNode* root){
        if(root==NULL)return 0;

        return 1+left(root->left);
    }
    int right(TreeNode* root){
        if(root==NULL)return 0;

        return 1+right(root->right);
    }

    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int l=left(root);
        int r=right(root);

        if(r==l)return pow(2,l)-1;

        return 1+countNodes(root->left) + countNodes(root->right);

    }
};