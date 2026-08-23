class Solution {
public:

    int solve(int amount, vector<int>& coins, int prev, vector<vector<int>>&dp){
        if(amount==0)return 1;

        if(dp[amount][prev]!=-1)return dp[amount][prev];

        int ans=0;
        for(int i=prev; i<coins.size(); i++){
            int co=coins[i];
            if(co<=amount){
                ans+=solve(amount-co, coins, i, dp);
            }
        }
        return dp[amount][prev]=ans;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        return solve(amount , coins, 0, dp);
    }
};