class ds{
    public:
    vector<int>parent;
    vector<long long>rank;

    ds(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int find_par(int u){
        if(parent[u]==u)return u;
        return parent[u]=find_par(parent[u]);
    }

    void unionr(int u, int v){
        int par_u=find_par(u);
        int par_v=find_par(v);\

        if(rank[par_u]<rank[par_v]){
            parent[par_u]=par_v;

        }else if(rank[par_u]>rank[par_v]){
            parent[par_v]=par_u;

        }else{
            parent[par_v]=par_u;
            rank[par_u]++;
        }
        return ;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c=connections.size();
        ds d(n);
        if(c<n-1)return -1;
        for(int i=0; i<c; i++){
            int u=connections[i][0];
            int v=connections[i][1];

            d.unionr(u,v);
        }

        // set<int>st;
        int ans=0;
        for(int i=0; i<n; i++){
            if(d.find_par(d.parent[i])==i)ans++;
        }

        return ans-1;
    }
};