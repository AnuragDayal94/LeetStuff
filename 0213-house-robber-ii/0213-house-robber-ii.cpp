class Solution {
public:

    int solve(vector<int>& nums, int s, int n){
        n=n-2+s;
        int n1=nums[n];
        int n2=0;
        for(int i=n-1; i>=s; i--){
            int curr=max(n1,(n2+nums[i]));
            n2=n1;
            n1=curr;
        }
        return n1;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(solve(nums,0,n),solve(nums,1,n));
    }
};