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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        stack<TreeNode*>s;
        stack<TreeNode*>s2;
        s.push(root);

        vector<int>ans;
        while(!s.empty()){
            auto curr=s.top();
            s.pop();

            s2.push(curr);
            if(curr->left != NULL)s.push(curr->left);
            if(curr->right != NULL)s.push(curr->right);

        }

        while(!s2.empty()){
            auto curr=s2.top();
            s2.pop();
            ans.push_back(curr->val);
        }

        return ans;

    }
};