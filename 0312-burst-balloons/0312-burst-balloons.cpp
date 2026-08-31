class Solution {
public:

    int solve(vector<int>& nums, int i, int j, vector<vector<int>>&dp){
        int n=nums.size();
        if((j-i)<2)return 0;

        if(dp[i+1][j+1]!=-1)return dp[i+1][j+1];

        int prev;
        int next;
        if(i<0)prev=1;
        else prev=nums[i];

        if(j>=n)next=1;
        else next=nums[j];

        // int count=prev*next*nums[i];

        int ans=0;
        for(int k=i+1; k<j; k++){
            int temp=solve(nums, k, j, dp)+solve(nums, i, k, dp)+(prev*next*nums[k]);
            ans=max(ans, temp);
        }
        return dp[i+1][j+1]=ans;
    }

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(nums, -1, n, dp);
    }
};