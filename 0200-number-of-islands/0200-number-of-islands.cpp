class Solution {
public:

    void solve(vector<vector<char>>& grid, vector<vector<bool>>&vis, int i, int j){
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            auto it=q.front();
            int x=it.first;
            int y=it.second;

            q.pop();
            vector<vector<int>>v{{1,0},{0,1},{-1,0},{0,-1}};
            for(int i=0; i<4; i++){
                int x1=x+v[i][0];
                int y1=y+v[i][1];

                if(x1>=0 && x1<m && y1>=0 && y1<n && !vis[x1][y1] && grid[x1][y1]=='1'){
                    q.push({x1,y1});
                    vis[x1][y1]=true;
                }
            }

        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    vis[i][j]=true;
                    solve(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};