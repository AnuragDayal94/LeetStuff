class Solution {
public:

    void bfs(vector<vector<int>>& mat,queue<pair<int,int>>& q,vector<vector<bool>>& vis){
        int m=mat.size();
        int n=mat[0].size();   
     
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
           
                //trevel
                int x=p.first;
                int y=p.second;

                for(auto &d:dir){
                    int nx=x+d[0];
                    int ny=y+d[1];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && mat[nx][ny]==1){
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                    mat[nx][ny]=mat[x][y]+1;
                }

                }
                
                // //left
                // if(y-1>=0 && !vis[x][y-1] && mat[x][y-1]==1){
                //     q.push({x,y-1});
                //     vis[x][y-1]=true;
                //     mat[x][y-1]=mat[x][y]+1;
                // }
               

                // //up
                // if(x-1>=0 && !vis[x-1][y] && mat[x-1][y]==1){
                //     q.push({x-1,y});
                //     vis[x-1][y]=true;
                //     mat[x-1][y]=mat[x][y]+1;
                // }
            

                // //right
                // if(y+1<n && !vis[x][y+1] && mat[x][y+1]==1){
                //     q.push({x,y+1});
                //     vis[x][y+1]=true;
                //     mat[x][y+1]=mat[x][y]+1;
                // }
               

                // //down
                // if(x+1<m && !vis[x+1][y] && mat[x+1][y]==1){
                //     q.push({x+1,y});
                //     vis[x+1][y]=true;
                //     mat[x+1][y]=mat[x][y]+1;
                // }

            
        }
       
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        int m=mat.size();
        int n=mat[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=true;
                    }                
            }
            
        }
        bfs(mat,q,vis);

        return mat;
        
    }
};