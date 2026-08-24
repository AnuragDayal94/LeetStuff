class Solution {
public:

    int solve(vector<int>& prices, int i, bool have, vector<vector<int>>&dp){
        int n=prices.size();
        if(i>=n)return 0;

        if(dp[i][have]!=-1)return dp[i][have];

        if(have){
            return dp[i][have]=max(solve(prices, i+1, have, dp),prices[i]+solve(prices, i+2, !have, dp));
        }
        return dp[i][have]=max(solve(prices, i+1, have, dp),-prices[i]+solve(prices, i+1, !have, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices, 0, false, dp);
    }
};