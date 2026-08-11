class ds{
    
    public:
    vector<int> parent;
    vector<long long>size;
    ds(int n){
        size.resize(n,0);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int find_par(int u){
        if(parent[u]==u)return u;
        return parent[u]=find_par(parent[u]);
    }

    void unions(int u, int v){
        int par_u=find_par(u);
        int par_v=find_par(v);

        if(size[par_u]<size[par_v]){
            parent[par_u]=par_v;
            // size[par_v]+=size[par_u];
        }
        else if(size[par_u]>size[par_v]){
            parent[par_v]=par_u;
            // size[par_u]+=size[par_v];
        }else{
            parent[par_v]=par_u;
            size[par_u]++;
        }
        return ;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<pair<int,int>>adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    adj.push_back({i,j});
                }
            }
        }

        ds d(n);
        for(int i=0; i<adj.size(); i++){
            int u=adj[i].first;
            int v=adj[i].second;

            d.unions(u,v);
        }

        set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(d.find_par(i));
        }

        return st.size();
    }
};