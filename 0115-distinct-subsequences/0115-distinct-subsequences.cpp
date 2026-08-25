class Solution {
public:

    int solve(string s, string t, int i, int j, vector<vector<int>>&dp){
        int n=t.size();
        int m=s.size();

        if(j>=n)return 1;
        if(i>=m && j<n)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==t[j]){

            return dp[i][j]=(solve(s, t, i+1, j+1, dp)+solve(s,t,i+1,j, dp));
        }
        return dp[i][j]=solve(s,t,i+1,j, dp);
    }

    int numDistinct(string s, string t) {
        int n=t.size();
        int m=s.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(s, t, 0, 0, dp);
    }
};