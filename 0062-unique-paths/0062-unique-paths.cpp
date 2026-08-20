class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>next(n+1,1);
        vector<int>curr(n+1,0);

        for(int i=0; i<m-1; i++){
            for(int j=n-1; j>=0; j--){
                curr[j]=curr[j+1]+next[j];
            }
            next=curr;
        }
        return next[0];
    }
};