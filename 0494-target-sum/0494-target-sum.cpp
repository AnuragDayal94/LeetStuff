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

    int solve2(vector<int>& nums, int target, int k, int total){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(total,0));
        if(target < -k || target > k)
            return 0;
        dp[n][target+k]=1;

        
        for(int i=n-1; i>=0; i--){
            for(int j=-k; j<=k; j++){
                int t1=j+nums[i];
                int t2=j-nums[i];
                int w=0;
                if(t1>=-k && t1<=k){
                    w+=dp[i+1][j+nums[i]+k];
                }
                if(t2>=-k && t2<=k){
                    w+=dp[i+1][j-nums[i]+k];
                }
                dp[i][j+k]=w;
            }
        }

        return dp[0][k];

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int k=accumulate(nums.begin(), nums.end(),0);
        int total=2*k + 1;
        
        return solve2(nums, target, k, total);
    }
};