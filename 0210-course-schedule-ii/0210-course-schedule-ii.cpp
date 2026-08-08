class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int,list<int>>adj(n);
        vector<int>ans;
        unordered_map<int, int>indeg(n);
        queue<int>q;

        for(int i=0; i<pre.size(); i++){
            int u=pre[i][0];
            int v=pre[i][1];

            adj[u].push_back(v);
            indeg[v]++;
        }

        for(int i=0; i<n; i++){
            if(indeg[i]==0)q.push(i);
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            ans.push_back(it);

            for(auto nbr: adj[it]){
                indeg[nbr]--;
                if(indeg[nbr]==0)q.push(nbr);
            }
        }

        if(ans.size()<n)return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};