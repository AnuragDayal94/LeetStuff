class Solution {
public:

    // bool solve(vector<int>& nums, int i, int s, int n, vector<vector<int>>&dp){
    //     if(s<=0)return true; 
    //     if(i>=n)return false;

    //     if(dp[i][s]!=-1)return dp[i][s];

    //     bool ans=solve(nums, i+1 , s, n, dp);
    //     if(nums[i]<=s){
    //         ans=ans|solve(nums, i+1, s-nums[i], n, dp);
    //     }
    //     return dp[i][s]=ans;
    // }

    bool solve(vector<int>& nums, int s, int n){
        // if(s<=0)return true; 
        // if(i>=n)return false;
        // vector<vector<int>>dp(n+1,vector<int>(s+1,0));
        vector<int>curr(s+1,0);
        vector<int>next(s+1,0);
        next[0]=1;
        
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=s; j++){
                bool ans=next[j];
                if(nums[i]<=j){
                    ans=ans|next[j-nums[i]];
                }

                curr[j]=ans;
            }
            next=curr;
        }
        
        return next[s];
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int s=(accumulate(nums.begin(), nums.end(),0));
        if(s&1)return false;
        s=s/2;
        // vector<vector<int>>dp(n+1,vector<int>(s+1,-1));
        return solve(nums, s, n);
    }
};