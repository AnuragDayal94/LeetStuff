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

    void solve(TreeNode* root, vector<int>& v){
        if(root==NULL)return;

        v.push_back(root->val);
        solve(root->left,v);
        solve(root->right,v);
        return;

    }

    void flatten(TreeNode* root) {
        if(root==NULL)return;
        vector<int>v;
        solve(root,v);
        // for(auto it:v){
        //     cout<<it<<" ";
        // }

        TreeNode* curr=root;
        int i=1;
        while(i<v.size()){
            curr->left=NULL;
            curr->right=new TreeNode(v[i]);
            curr=curr->right;
            i++;
        }
        return;

    }
};