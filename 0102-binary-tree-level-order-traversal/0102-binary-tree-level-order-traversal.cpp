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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>temp;

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front==NULL){
                if(temp.size()==0)break;
                ans.push_back(temp);
                temp.clear();
                q.push(NULL);
            }else{
                temp.push_back(front->val);
                TreeNode* left=front->left;
                if(left!=NULL)q.push(left);

                TreeNode* right=front->right;
                if(right!=NULL)q.push(right);
            }
        }
        return ans;
    }
};