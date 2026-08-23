class Solution {
public:

    int solve(string s, int i, int j, vector<vector<int>>&dp){
        if(j<i)return 0;

        if(i==j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==s[j])return 2+solve(s,i+1,j-1,dp);
        return dp[i][j]=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    }

    int solve3(string s){
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==j)dp[i][j]=1;
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j])dp[i][j]=2+dp[i+1][j-1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }

    int solve2(string s){
        int n=s.length();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        

        // for(int i=0; i<n+1; i++){
        //     for(int j=0; j<n+1; j++){
        //         if(i==j)dp[i][j]=1;
        //     }
        // }

        for(int i=n-1; i>=0; i--){
            curr[i]=1;
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j])curr[j]=2+next[j-1];
                else curr[j]=max(next[j],curr[j-1]);
            }
            next=curr;
        }
        return next[n-1];
    }

    int longestPalindromeSubseq(string s) {
        int n=s.length();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve2(s);
    }
};