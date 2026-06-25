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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        vector<int>ans;
        stack<TreeNode*>s;

        s.push(root);
        while(!s.empty()){
            auto front=s.top();
            s.pop();
            ans.push_back(front->val);

            TreeNode* left=front->left;
            TreeNode* right=front->right;

            if(right!=NULL)s.push(right);
            if(left!=NULL)s.push(left);
        }
        return ans;
    }
};