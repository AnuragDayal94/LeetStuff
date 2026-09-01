class Solution {
public:

    
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {

                if(s[i] == s[j] &&
                   (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }
        vector<int>dp(n+1);

        for(int i=0; i<n; i++){
            if(pal[0][i]){
                dp[i]=0;
                continue;
            }
            dp[i]=i;
            for(int j=1; j<=i; j++){
                if(pal[j][i]){
                    dp[i]=min(dp[i], 1+dp[j-1]);
                }
            }
        }

        return dp[n-1];
    }
};