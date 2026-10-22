class Solution {
public:

    int solve(int u, string& colors){
        if(colors[u]=='R')return 0;
        else if(colors[u]=='B')return 1;
        return 2;
    }

    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n=colors.length();
        
        vector<int> indeg(n); 
        vector<int> outdeg(n);

        for(int i=0; i<n-1; i++){
            int u=edges[i][0];
            int v=edges[i][1];
             
            int cu=solve(u, colors);
            int cv=solve(v, colors);

            if(cu==cv)return -1;

            if((cu+1)%3==cv){
                outdeg[u]++;
                indeg[v]++;
            }else{
                outdeg[v]++;
                indeg[u]++;
            }
        }

        int ans=-1;
        for(int i=0; i<n; i++){
            if(outdeg[i]>2)return -1;

            if(indeg[i]==0){
                if(ans!=-1)return -1;
                ans=i;
            }else if(indeg[i]!=1)return -1;
        }
        return ans;
    }
};