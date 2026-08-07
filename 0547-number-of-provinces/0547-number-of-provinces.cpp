class Solution {
public:

    unordered_map<int,list<int>>adj;

    void solve(int i, vector<bool>& vis){
        queue<int>q;
        q.push(i);
        vis[i]=true;

        while(!q.empty()){
            int it=q.front();
            q.pop();

            for(auto node:adj[it]){
                if(!vis[node]){
                    vis[node]=true;
                    q.push(node);
                }
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        for(int i=0; i<n; i++){
            int u=i;
            for(int j=0; j<isConnected[i].size(); j++){
                int v=j;
                if(isConnected[i][j]){
                    adj[u].push_back(v);
                    adj[v].push_back(u);

                }
            }
        }

        // 

        int ans=0;
        vector<bool>vis(n,false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                solve(i,vis);
            }
        }

        return ans;
    }
};