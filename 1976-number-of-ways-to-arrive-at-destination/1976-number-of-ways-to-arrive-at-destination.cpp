class Solution {
public:

    int mod=1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,list<pair<int,int>>>adj(n);
        for(int i=0; i<roads.size(); i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});

        }

        vector<long long>dis(n,LLONG_MAX);
        vector<int>count(n,0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>q;
        q.push({0,0});
        dis[0]=0;
        count[0]=1;

        while(!q.empty()){
            auto it=q.top();
            long long val=it.first;
            int curr=it.second;
            q.pop();

            for(auto nbr:adj[curr]){
                int x=nbr.first;
                int w=nbr.second;

                if((val+w)<dis[x]){
                    dis[x]=val+w;
                    count[x]=count[curr];
                    q.push({dis[x],x});
                }else if((val+w)==dis[x]){
                    count[x]=(count[x]+count[curr])%mod;
                }
            }
        }

        return count[n-1];
    }
};