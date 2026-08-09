class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n=g.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        if(g[0][0]==0){
            q.push({0,0});
            dist[0][0]=1;
        }

        while(!q.empty()){
            auto it=q.front();
            int x=it.first;
            int y=it.second;

            q.pop();

            vector<vector<int>>v{{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
            for(int i=0; i<8; i++){
                int x1=x+v[i][0];
                int y1=y+v[i][1];

                if(x1>=0 && x1<n && y1>=0 && y1<n && g[x1][y1]==0){
                    if((dist[x][y]+1)<dist[x1][y1]){
                        q.push({x1,y1});
                        dist[x1][y1]=dist[x][y]+1;
                    }
                }

            }
        }

        if(dist[n-1][n-1]==INT_MAX)return -1;
        return dist[n-1][n-1];
        
    }
};