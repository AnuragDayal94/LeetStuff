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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>ans;
        vector<int>temp;
        queue<TreeNode*>q;
        bool flag=false;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front==NULL){

                if(flag)reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                if(q.size()==0)break;                

                q.push(NULL);

                flag=!flag;
                temp.clear();

            }
            else{
                temp.push_back(front->val);
                if(front->left!=NULL)q.push(front->left);
                if(front->right!=NULL)q.push(front->right);

            }
        }
        return ans;
    }
};