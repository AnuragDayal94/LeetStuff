class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k=k-1;
        unordered_map<int,list<pair<int,int>>>adj(n);
        for(int i=0; i<times.size(); i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int wt=times[i][2];

            adj[u].push_back({v,wt});
        }

        vector<int>d(n,INT_MAX);
        d[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,k});

        while(!q.empty()){
            auto it=q.top();
            int val=it.first;
            int curr=it.second;
            q.pop();

            for(auto nbr:adj[curr]){
                if((val+nbr.second)<d[nbr.first]){
                    d[nbr.first]=(val+nbr.second);
                    q.push({d[nbr.first],nbr.first});
                }
            }
        }
        int ans=INT_MIN;
        for(auto i:d){
            if(i==INT_MAX)return -1;
            ans=max(ans,i);
        }
        return ans;
    }
};