class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int prev=nums[n-1];
        for(int i=n-2; i>=0; i--){
            int curr=nums[i];
            if(curr%prev==0){
                ans+=(curr/prev)-1;
            }else{
                int k=(curr/prev)+1;
                ans+=(curr/prev);
                prev=curr/k;
            }
        }
        return ans;
    }
};