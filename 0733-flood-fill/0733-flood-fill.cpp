class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        int prev= image[sr][sc];
        image[sr][sc]=color;

        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vis[sr][sc]=true;

        while(!q.empty()){
            auto it=q.front();
            int x=it.first;
            int y=it.second;

            q.pop();

            vector<vector<int>>v{{1,0},{0,1},{-1,0},{0,-1}};
            for(int i=0; i<4; i++){
                int x1=v[i][0];
                int y1=v[i][1];

                if((x+x1)>=0 && (x+x1)<m && (y+y1)>=0 && (y+y1)<n){
                    if(!vis[x+x1][y+y1] && image[x+x1][y+y1]==prev){
                        image[x+x1][y+y1]=color;
                        q.push({x+x1,y+y1});
                        vis[x+x1][y+y1]=true;
                    }
                }
            }
        }
        return image;

    }
};