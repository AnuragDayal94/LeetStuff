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

    int solve2(int k, vector<int>& prices){
        int n=prices.size();
        vector<vector<int>>curr(2, vector<int>(2*k +1));
        vector<vector<int>>next(2, vector<int>(2*k +1,0));

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int z=1; z<=2*k; z++){
                    if(j)curr[j][z]=max(next[j][z],prices[i]+curr[!j][z-1]);
                    else curr[j][z]=max(next[j][z],-prices[i]+curr[!j][z-1]);
                }
            }
            next=curr;
        }

        return next[0][2*k];

    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2, vector<int>(2*k +1,-1)));
        return solve2(k, prices);
    }
};