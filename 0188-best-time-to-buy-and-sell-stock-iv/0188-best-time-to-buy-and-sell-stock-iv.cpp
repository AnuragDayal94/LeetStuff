class Solution {
public:

    int solve(vector<int>& prices, int i, bool have, int k, vector<vector<vector<int>>>&dp){
        int n=prices.size();
        if(k<=0)return 0;
        if(i>=n)return 0;

        if(dp[i][have][k]!=-1)return dp[i][have][k];


        if(have){
            return dp[i][have][k]=max(solve(prices, i+1, have, k, dp), prices[i]+solve(prices, i+1, !have, k-1, dp));
        }
        return dp[i][have][k]=max(solve(prices, i+1, have, k, dp), -prices[i]+solve(prices, i+1, !have, k-1, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2, vector<int>(2*k +1,-1)));
        return solve(prices, 0, false, 2*k, dp);
    }
};