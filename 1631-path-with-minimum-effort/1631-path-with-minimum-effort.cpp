class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m=h.size();
        int n=h[0].size();

        vector<vector<int>>v(m,vector<int>(n,INT_MAX));
        v[0][0]=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0,0,0});
        int ans=0;

        while(!pq.empty()){
            auto it=pq.top();
            int val = it[0];
            int x = it[1];
            int y = it[2];
            pq.pop();

            if(x==m-1 && y==n-1){
                ans=val;
                break;
            }

            vector<vector<int>>vec{{0,1},{1,0},{-1,0},{0,-1}};
            for(int i=0; i<4; i++){
                int x1=x+vec[i][0];
                int y1=y+vec[i][1];

                if(x1>=0 && x1<m && y1>=0 && y1<n){
                    int diff=abs(h[x1][y1]-h[x][y]);
                    if(max(diff,val)<v[x1][y1]){
                        v[x1][y1]=max(diff,val);
                        pq.push({v[x1][y1],x1,y1});
                    }
                }
            }
        }

        return ans;
    }

};