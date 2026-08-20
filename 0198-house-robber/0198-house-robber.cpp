class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        // vector<int>dp(n+1,0);
        // dp[n-1]=nums[n-1];
        int n1=nums[n-1];
        int n2=0;
          
        for(int i=n-2; i>=0; i--){
            int curr=max(n1,(n2+nums[i]));
            n2=n1;
            n1=curr;
        }

        return n1;
    }
};