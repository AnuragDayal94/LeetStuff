class Solution {
public:

    void solve(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        vector<int>last_col(m);
        for(int i=0; i<m; i++){
            last_col[i]=grid[i][n-1];
        }

        for(int i=n-1; i>=1; i--){
            for(int j=0; j<m; j++){
                grid[j][i]=grid[j][i-1];
            }
        }

        grid[0][0]=last_col[m-1];
        for(int i=1; i<m; i++){
            grid[i][0]=last_col[i-1];
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        while(k){
            solve(grid);
            k--;
        }
        return grid;
    }
};