class Solution {
public:

    bool dfs(unordered_map<int,list<int>>& adj, vector<bool>& vis, unordered_map<int,int>& map, int i){
        int ans=false;

        for(auto it: adj[i]){
            if(!vis[it]){
                vis[it]=true;
                map[it]++;
                ans=ans|dfs(adj, vis, map, it);
                map[it]--;
            }else if(map[it])return true;
        }
        return ans;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,list<int>>adj(n);
        unordered_map<int,int>map(n);
        vector<bool>vis(n,false);

        for(int i=0; i<pre.size(); i++){
            int u=pre[i][0];
            int v=pre[i][1];
            adj[u].push_back(v);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i]=true;
                map[i]++;
                bool is=dfs(adj,vis,map,i);
                map[i]--;
                if(is)return false;
            }
        }
        return true;
    }
};