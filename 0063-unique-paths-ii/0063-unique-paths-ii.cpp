class Solution {
public:

    

    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int m=o.size();
        int n=o[0].size();
        if(o[m-1][n-1]==1)return 0;

        vector<long long>next(n+1,0);
        if(o[m-1][n-1]==0)next[n-1]=1;

        for(int i=n-2; i>=0; i--){
            if(o[m-1][i]==1)next[i]=0;
            else next[i]=next[i+1];
        }
        vector<long long>curr(n+1,0);

        for(int i=m-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(o[i][j]==1){
                    curr[j]=0;
                    continue;
                }
                curr[j]=(curr[j+1]+next[j]);
            }
            next=curr;
        }
        return next[0];
        
    }
};