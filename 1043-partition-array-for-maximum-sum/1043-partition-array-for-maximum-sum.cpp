class Solution {
public:

    int solve(vector<int>&arr, int k, int i, vector<int>&dp){
        int n=arr.size();
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];

        int mult=arr[i];
        int ans=INT_MIN;
        for(int j=0; j<k; j++){
            int temp=i+j;
            if(temp<n){
                mult=max(mult, arr[temp]);
                ans=max(ans, (j+1)*mult + solve(arr, k, temp+1, dp));
            }
        }
        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1, -1);
        return solve(arr, k, 0, dp);
    }
};