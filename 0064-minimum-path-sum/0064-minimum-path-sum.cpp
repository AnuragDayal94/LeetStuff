class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>next(n+1,INT_MAX);
        vector<int>curr(n+1,INT_MAX);

        int psum=0;
        for(int i=n-1; i>=0; i--){
            psum+=grid[m-1][i];
            next[i]=psum;
        }

        for(int i=m-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                curr[j]=grid[i][j]+min(curr[j+1],next[j]);
            }
            next=curr;
        }
        return next[0];

    }
};