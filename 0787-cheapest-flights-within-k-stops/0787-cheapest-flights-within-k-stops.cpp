class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>>adj(n);
        for(int i=0; i<f.size(); i++){
            int u=f[i][0];
            int v=f[i][1];
            int wt=f[i][2];
            adj[u].push_back({v,wt});

        }

        vector<pair<int,int>>dis(n,{INT_MAX,k});
        dis[src]={0,k};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({dis[src].first,src,dis[src].second});
        int ans=INT_MAX;

        while(!pq.empty()){
            auto it=pq.top();
            int val=it[0];
            int curr=it[1];
            int stop=it[2];
            pq.pop();

            if(curr==dst){
                ans=min(ans,val);
            }
            if(stop==-1){
                continue;
            }

            for(auto nbr:adj[curr]){
                int x=nbr.first;
                int pr=nbr.second;
                
                if(val+pr<dis[x].first || stop-1>dis[x].second){
                    dis[x].first=val+pr;
                    dis[x].second=stop-1;

                    pq.push({dis[x].first,x,dis[x].second});
                }
            }

        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};