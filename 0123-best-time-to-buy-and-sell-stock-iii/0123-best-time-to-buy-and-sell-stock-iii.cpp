class Solution {
public:

    int solve(vector<int>& prices, int i, bool have, vector<vector<vector<int>>>&dp, int k){
        int n=prices.size();
        if(k<=0)return 0;
        if(i>=n)return 0; 
        if(dp[i][have][k]!=-1)return dp[i][have][k];

        int ans=0;
        if(have){
            return dp[i][have][k]=max(solve(prices, i+1, have, dp, k), prices[i]+solve(prices, i+1, !have, dp, k-1));
        }
        return dp[i][have][k]=max(solve(prices, i+1, have, dp, k), solve(prices, i+1, !have, dp,k-1)-prices[i]);
    }

    int solve2(vector<int>& prices){
        int n=prices.size();
        vector<int>curr(2);
        vector<int>next(2,0);

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j)curr[j]=max(next[j],prices[i]+next[!j]);
                else curr[j]=max(next[j],-prices[i]+next[!j]);
            }
            next=curr;
        }

        return next[0];

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(5,-1)));
        return solve(prices, 0, false, dp, 4);
    }
};