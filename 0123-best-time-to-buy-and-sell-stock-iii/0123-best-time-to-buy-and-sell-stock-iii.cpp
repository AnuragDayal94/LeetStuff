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
        vector<vector<int>>curr(2, vector<int>(5));
        vector<vector<int>>next(2, vector<int>(5,0));

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int k=1; k<5; k++){
                    if(j)curr[j][k]=max(next[j][k],prices[i]+next[!j][k-1]);
                    else curr[j][k]=max(next[j][k],-prices[i]+next[!j][k-1]);
                }
                
            }
            next=curr;
        }

        return next[0][4];

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(5,-1)));
        return solve2(prices);
    }
};