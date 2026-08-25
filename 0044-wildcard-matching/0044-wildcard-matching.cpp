class Solution {
public:

    bool solve(string& s, string& p, int i, int j, vector<vector<int>>&dp){
        int m=s.length();
        int n=p.length();

        if(i==m && j==n)return true;
        if(j>=n)return i==m;

        if(i == m){
            for(int k = j; k < n; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        

        if(dp[i][j]!=-1)return dp[i][j];

        bool ans=false;
        if(s[i]==p[j])ans=ans|solve(s,p,i+1,j+1,dp);
        else{
            if(p[j]=='?'){
                ans|=solve(s, p, i+1, j+1, dp);
            }else if(p[j]=='*'){
                
                    ans = solve(s, p, i, j+1, dp) || solve(s, p, i+1, j, dp);
                
            }else{
                ans=false;
            }
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(s, p, 0, 0,dp);    
    }
};