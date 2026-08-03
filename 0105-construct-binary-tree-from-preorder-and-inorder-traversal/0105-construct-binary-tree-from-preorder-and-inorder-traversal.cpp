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

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int s, int e, int & i){
        if(s==e){
            TreeNode* temp=new TreeNode(preorder[i]);
            i++;
            return temp;
        }
        if(e<s){
            // i++;
            return NULL;
            }

        int val=preorder[i];
        int j=0;
        for( j=s; j<=e; j++){
            if(inorder[j]==val)break;
        }
        i++;
        TreeNode* left=solve(preorder,inorder,s,j-1,i);
        // i++;
        TreeNode* right=solve(preorder,inorder,j+1,e,i);

        TreeNode* ans=new TreeNode(val,left,right);
        return ans;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s=0;
        int e=inorder.size()-1;
        int i=0;
        TreeNode* ans=solve(preorder,inorder,s,e,i);
        return ans;
    }
};