class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int tre) {
        vector<vector<long long>>adj(n,vector<long long>(n,LLONG_MAX));
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];

            adj[u][v]=w;
            adj[v][u]=w;
        }
        for(int i=0; i<n; i++){
            adj[i][i]=0;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                if (adj[i][k] == LLONG_MAX)
                    continue;
                for(int j=0; j<n; j++){
                    if (adj[k][j] == LLONG_MAX)continue;
                    
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }

        // vector<int>min(n,0);
        int mini=INT_MAX;
        int ans=0;
        for(int i=0; i<n; i++){
            int temp=0;
            for(int j=0; j<n; j++){
                if(i==j)continue;

                if(adj[i][j]<=tre)temp++;

            }
            if(temp<=mini){
                mini=temp;
                ans=i;
            }
        }
        return ans;
    }
};