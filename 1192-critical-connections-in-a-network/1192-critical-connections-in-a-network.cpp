class Solution {
public:

    int time=1;
    void dfs(unordered_map<int,list<int>>&adj, vector<bool>&vis, vector<int>&low, vector<int>&tin, vector<vector<int>>&ans, int node, int parent){
        vis[node]=true;
        low[node]=tin[node]=time;
        time++;

        for(auto it:adj[node]){
            if(it==parent)continue;

            if(!vis[it]){
                dfs(adj, vis, low, tin, ans, it, node);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({it,node});
                }
            }else{
                low[node]=min(low[node],low[it]);
                
            }
        }
        return;

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adj(n);
        vector<int>low(n);
        vector<int>tin(n);                        
        vector<bool>vis(n,false);

        for(int i=0; i<connections.size(); i++){
            int u=connections[i][0];
            int v=connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }                     

        vector<vector<int>>ans;

        dfs(adj, vis, low, tin, ans, 0, -1);

        return ans;
    }
};