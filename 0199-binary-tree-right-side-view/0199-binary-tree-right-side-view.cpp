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

    void solve(TreeNode* root, int lev, map<int,int>& map){
        if(root==NULL)return;

        int num=root->val;
        if(map.find(lev)==map.end()){
            map[lev]=num;
        }
        solve(root->right,lev+1,map);
        solve(root->left,lev+1,map);
        return ;

    }

    vector<int> rightSideView(TreeNode* root) {
        map<int,int>map;
        solve(root,0,map);
        vector<int>ans;

        for(auto it:map){
            ans.push_back(it.second);
        }
        return ans;
    }
};