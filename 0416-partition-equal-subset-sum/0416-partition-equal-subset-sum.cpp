class Solution {
public:

    bool solve(vector<int>& nums, int i, int s, int n, vector<vector<int>>&dp){
        if(s<=0)return true; 
        if(i>=n)return false;

        if(dp[i][s]!=-1)return dp[i][s];

        bool ans=solve(nums, i+1 , s, n, dp);
        if(nums[i]<=s){
            ans=ans|solve(nums, i+1, s-nums[i], n, dp);
        }
        return dp[i][s]=ans;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=(accumulate(nums.begin(), nums.end(),0));
        if(s&1)return false;
        s=s/2;
        vector<vector<int>>dp(n+1,vector<int>(s+1,-1));
        return solve(nums, 0, s, n, dp);
    }
};