class Solution {
public:

    int solve(vector<int>& nums, int target, int i, int sum, vector<vector<int>>&dp, int k){
        int n=nums.size();
        if(i>=n){
            if(sum==target)return 1;
            return 0;
        }
        if(dp[i][sum+k]!=-1)return dp[i][sum+k];
        return dp[i][sum+k]=solve(nums, target, i+1, sum+nums[i], dp, k)+solve(nums, target, i+1, sum-nums[i], dp, k);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int k=accumulate(nums.begin(), nums.end(),0);
        int total=2*k + 1;
        vector<vector<int>>dp(n+1,vector<int>(total,-1));
        return solve(nums, target, 0, 0, dp, k);
    }
};