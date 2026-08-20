class Solution {
public:

    int solve(int n, int i, vector<int>&dp){
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];        

        return dp[i]=solve(n,i+1,dp)+solve(n,i+2,dp);
    }

    int climbStairs(int n) {
        int n1=1;
        int n2=0;
        for(int i=n-1; i>=0; i--){
            int curr=n1+n2;
            n2=n1;
            n1=curr;
        }
        return n1;
    }
};