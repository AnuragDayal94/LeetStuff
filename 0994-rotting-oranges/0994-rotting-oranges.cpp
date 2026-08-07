class Solution {
public:

    int solve(vector<vector<int>>& grid, queue<pair<int,int>>&q, vector<vector<bool>>&vis){
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();

        while(!q.empty()){
            auto it=q.front();
            int x=it.first;
            int y=it.second;
            q.pop();

            if(x==-1){
                if(q.empty())break;
                ans++;
                q.push({-1,-1});
                continue;
            }

            vector<vector<int>>v{{1,0},{0,1},{0,-1},{-1,0}};

            for(int i=0; i<4; i++){
                
                int x1=v[i][0];
                int y1=v[i][1];
                
                if((x+x1)>=0 && (x+x1)<m && (y+y1)>=0 && (y+y1)<n ){
                    if(!vis[x+x1][y+y1] && grid[x+x1][y+y1]==1){
                        q.push({x+x1,y+y1});
                        vis[x+x1][y+y1]=true;

                    }
                }                
            }
        }

        return ans;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }

        q.push({-1,-1});

        int ans=solve(grid,q,vis);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }

        return ans;
        
    }
};