class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n+2,0);
        dp[n-1]=nums[n-1];

        for(int i=n-2; i>=0; i--){
            dp[i]=max(dp[i+1],(dp[i+2]+nums[i]));
        }

        return dp[0];
    }
};