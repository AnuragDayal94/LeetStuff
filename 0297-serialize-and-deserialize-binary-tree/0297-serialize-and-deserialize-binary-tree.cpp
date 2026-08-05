/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)return "#,";
        string s="";
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            if(it==NULL){
                s+="#,";
                continue;
            }

            int val=it->val;
            // char ch = val + '0';
            s += to_string(val) + ",";

            q.push(it->left);
            q.push(it->right);

        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='#')return NULL;
        int i=0;
        queue<TreeNode*>q;
        int j=i;
        while(data[j]!=',')j++;
        int val=stoi(data.substr(i,j-i));
        i=j+1;     

        TreeNode* t=new TreeNode(val);
        q.push(t);
        
        while(!q.empty() && i<data.size()){
            auto it=q.front();
            q.pop();
            
            if (i >= data.size()) break;
            char c=data[i];
            if(c!='#'){
                j=i;
                while(data[j]!=',')j++;
                int v=stoi(data.substr(i,j-i));
                i=j+1; 
                TreeNode* temp=new TreeNode(v);
                it->left=temp;
                q.push(temp);
            }else{
                i+=2;
            }
            if (i >= data.size()) break;
            c=data[i];
            if(c!='#'){
                j=i;
                while(data[j]!=',')j++;
                int v=stoi(data.substr(i,j-i));
                i=j+1; 
                TreeNode* temp=new TreeNode(v);
                it->right=temp;
                q.push(temp);
            }else{
                i+=2;
            }

        }
        return t;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));