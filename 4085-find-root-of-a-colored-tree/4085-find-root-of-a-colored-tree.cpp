class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int ans=-1;
        // vector<char>col={R,B,W};
        unordered_map<int, list<int>>adj;
        unordered_map<char,char>col;
        col['R']='B';
        col['B']='W';
        col['W']='R';
        
        
        
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);          
            if(adj[u].size()>=4 || adj[v].size()>=4)return -1;
            
        }

        vector<int>may;
        for(int i=0; i<=edges.size(); i++){
            if(adj[i].size()<=2)may.push_back(i);
        }

        for(auto i:may){
            cout<<1;
            ans=i;
            queue<pair<char,vector<int>>>q;
            q.push({colors[i],{i, -1}});
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                int curr=it.second[0];
                int prev=it.second[1];
                int r=it.first;

                if(r!=colors[curr]){
                    ans=-1;
                    break;
                    }
                for(auto nbr:adj[curr]){
                    if(nbr!=prev){
                        q.push({col[r],{nbr,curr}});
                    }
                }
            }
            if(ans!=-1)return ans;
        }
        return ans;
    }
};