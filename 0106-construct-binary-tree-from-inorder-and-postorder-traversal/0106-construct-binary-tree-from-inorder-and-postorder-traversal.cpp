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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int s, int e, int & i){
        if(s==e){
            TreeNode* temp=new TreeNode(postorder[i]);
            i--;
            return temp;
        }
        if(e<s)return NULL;

        int val=postorder[i];
        int j=0;
        for(j=s; j<=e; j++){
            if(inorder[j]==val)break;
        }
        i--;
        TreeNode* right=solve(inorder,postorder,j+1,e,i);

        TreeNode* left=solve(inorder,postorder,s,j-1,i);

        TreeNode* ans=new TreeNode(val,left,right);
        return ans;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int s=0;
        int e=inorder.size()-1;
        int i=postorder.size()-1;
        TreeNode* ans=solve(inorder,postorder,s,e,i);
        return ans;
    }
};