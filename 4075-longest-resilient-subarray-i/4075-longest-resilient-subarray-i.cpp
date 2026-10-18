class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int l=1;
        int ans=1;
        int sum=nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i]%k==nums[i-1]%k){
                l++;
                sum=sum+nums[i];
            }
            else{
                l=1;
                sum=nums[i];
            }

            if(((nums[i]%k)*(l-1))%k==0){
                ans=max(ans,l);

            }
        }
        return ans;
    }
};