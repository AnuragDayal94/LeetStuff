class Solution {
public:

    void solve(vector<vector<int>>& mat, queue<pair<int,int>>&q, vector<vector<bool>>&vis){
        int m=mat.size();
        int n=mat[0].size();
        

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int x=it.first;
            int y=it.second;

            vector<vector<int>>v{{1,0},{0,1},{-1,0},{0,-1}};

            for(int i=0; i<4; i++){
                int x1=x+v[i][0];
                int y1=y+v[i][1];

                if(x1>=0 && x1<m && y1>=0 && y1<n && !vis[x1][y1] && mat[x1][y1]==1){
                        q.push({x1,y1});
                        vis[x1][y1]=true;
                        mat[x1][y1]=mat[x][y]+1;                      
                    
                }
            }

        }
        return ;


    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        // vector<vector<int>>ans(m, vector<int>(n));
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    q.push({i,j});
                    
                }
                
            }
        }
        solve(mat,q,vis);
        return mat;
    }
};