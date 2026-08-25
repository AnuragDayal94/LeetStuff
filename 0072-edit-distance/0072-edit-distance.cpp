class Solution {
public:

    int solve(string s, string t, int i, int j, vector<vector<int>>&dp){
        int m=s.length();
        int n=t.length();

        if(j>=n){
            return m-i;
        }
        if(i>=m)return n-j;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==t[j]){
            return solve(s, t, i+1, j+1, dp);
        }
        int o= min(1+solve(s, t, i+1, j+1, dp),1+solve(s, t, i+1,j, dp));
        int to= min(1+solve(s, t, i+1, j+1, dp),1+solve(s, t, i,j+1, dp));
        return dp[i][j]=min(o,to);

    }

    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return solve(word1, word2, 0, 0, dp);
    }
};