class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();

        for(int i=0; i<n; i++){
            unordered_set<int>rem;
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=nums[j];

                if(((sum%k)+k)%k==0)ans=max(ans, j-i+1);

                int r=((sum%k)+k)%k;
                rem.insert((((2*nums[j])%k)+k)%k);
                if(rem.count(r))ans=max(ans, j-i+1);
            }
        }
        return ans;
    }
};