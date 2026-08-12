class ds{
    public:
    vector<int> parent, rank;
    ds(int n){
        parent.resize(n);
        rank.resize(n,1);
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
        int par_v=find_par(v);

        if(rank[par_u]>rank[par_v]){
            parent[par_v]=parent[par_u];
        }else if(rank[par_u]<rank[par_v]){
            parent[par_u]=parent[par_v];
        }else{
            parent[par_u]=parent[par_v];
            rank[par_v]++;
        }

        return; 
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        ds d(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x=stones[i][0];
                int y=stones[i][1];

                int a=stones[j][0];
                int b=stones[j][1];

                if(x==a || y==b){
                    d.unionr(i,j);
                }

            }
        }

        int count=0;
        for(int i=0; i<n; i++){
            if(d.parent[d.find_par(i)]==i)count++;
        }

        return n-count;
    }
};