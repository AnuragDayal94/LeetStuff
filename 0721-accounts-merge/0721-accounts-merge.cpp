class ds{
    public:
    vector<int> parent, rank;

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
        int par_v=find_par(v);
        
        if(rank[par_u]<rank[par_v]){
            parent[par_u]=parent[par_v];
        }else if(rank[par_u]>rank[par_v]){
            parent[par_v]=parent[par_u];
        }else{
            parent[par_v]=parent[par_u];
            rank[par_u]++;
        }
        return ;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string, int>map;
        ds d(n);
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string s=accounts[i][j];
                if(map.find(s)==map.end()){
                    map[s]=i;
                }else{
                    d.unionr(map[s],i);
                }
            }
        }

        vector<vector<string>>merge(n);
        for(auto it:map){
            string mail=it.first;
            int node=d.parent[d.find_par(it.second)];
            merge[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(merge[i].size()==0)continue;

            sort(merge[i].begin(), merge[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merge[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};