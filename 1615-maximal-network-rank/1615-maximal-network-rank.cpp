class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>count(n, 0);
        vector<vector<int>>adj(n);
        for(int i=0; i<roads.size(); i++){
            int u=roads[i][0];
            int v=roads[i][1];

            
            adj[u].push_back(v);
            adj[v].push_back(u);

            count[u]++;
            count[v]++;
        }

        // sort(count.begin(), count.end(), greater<int>());
        vector<pair<int,int>>p;
        for(int i=0; i<n; i++){
            p.push_back({i,count[i]});
        }
        sort(p.begin(), p.end(), [](pair<int, int>&a, pair<int, int>& b){
            return a.second>b.second;
        });

         int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int val = count[i] + count[j];

                if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                    val--;
                }

                ans = max(ans, val);
            }
        }

        return ans;
    }
};