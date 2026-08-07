class Solution {
public:

    unordered_map<int,list<int>>adj;

    bool solve(vector<vector<int>>& graph, vector<int>& v, int i){
        v[i]=0;
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            for(auto nbr:adj[it]){
                if(v[nbr]==-1){
                    q.push(nbr);
                    if(v[it]==1)v[nbr]=0;
                    else v[nbr]=1;
                }else if(v[nbr]==v[it])return true;
            }
        }

        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int>v(n,-1);
        for(int i=0; i<n; i++){
            if(v[i]==-1){
                bool temp=solve(graph,v,i);
                if(temp)return false;
            }
        }
        
        return true;
    }
};