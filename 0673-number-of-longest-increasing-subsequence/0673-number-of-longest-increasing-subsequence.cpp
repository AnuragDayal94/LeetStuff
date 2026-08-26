class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);


        int ans=1;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                                       
                        dp[i]=1+dp[j];
                        count[i]=count[j];

                                                
                }else if(nums[i]>nums[j] && dp[j]+1==dp[i]){
                        count[i]=count[i]+count[j];
                }
            }
            if(dp[i]>ans ){
                ans=dp[i];
                
            }
        }

        int c=0;
        for(int i=0; i<n; i++){
           if(dp[i]==ans){
            c=c+count[i];
           }
        }
        // cout<<ans<<endl;
        // if(ans==1)return n;
        return c;
    }
};