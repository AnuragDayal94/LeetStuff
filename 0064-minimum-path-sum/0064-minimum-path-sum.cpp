class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        dis[0][0]=grid[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>q;
        q.push({dis[0][0],0,0});
        while(!q.empty()){
            auto it=q.top();
            q.pop();

            int val=it[0];
            int x=it[1];
            int y=it[2];

            if(val>dis[x][y])continue;
            vector<vector<int>>v={{0,1},{1,0}};
            for(auto j:v){
                int x1=x+j[0];
                int y1=y+j[1];

                if(x1>=0 && x1<m && y1>=0 && y1<n){
                    if((val+grid[x1][y1])<dis[x1][y1]){
                        dis[x1][y1]=(val+grid[x1][y1]);
                        q.push({dis[x1][y1],x1,y1});
                    }
                }
            }

        }

        return dis[m-1][n-1];
        
    }
};