/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*,TreeNode*>map;

    void parent(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it->left!=NULL){
                map[it->left]=it;
                q.push(it->left);
            }
            if(it->right!=NULL){
                map[it->right]=it;
                q.push(it->right);
            }
        }
        return;
    }

    vector<int> solve(TreeNode* root, int k){
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        q.push({NULL,-1});
        vector<bool>vis(501,false);
        vis[root->val]=true;

        while(!q.empty()){
            auto it=q.front();
            if(it.second==k)break;

            q.pop();
            if(it.first==NULL){
                if(q.empty())break;
                else{
                    q.push({NULL,-1});
                    continue;
                }
            }
            int val=it.second;
            auto curr=it.first;
            vis[curr->val]=true;
            if(map[curr]!=NULL && !vis[map[curr]->val]){
                q.push({map[curr],val+1});
            }
            if(curr->left!=NULL && !vis[curr->left->val]){
                q.push({curr->left,val+1});

            }
            if(curr->right!=NULL && !vis[curr->right->val]){
                q.push({curr->right,val+1});

            }
        }

        vector<int>ans;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it.first==NULL)continue;

            ans.push_back(it.first->val);
        }
        return ans;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent(root);

        vector<int> ans=solve(target, k);
        return ans;
    }
};