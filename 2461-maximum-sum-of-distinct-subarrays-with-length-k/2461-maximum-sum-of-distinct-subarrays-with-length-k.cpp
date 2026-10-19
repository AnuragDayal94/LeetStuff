class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();

        int i=0; int j=0;
        long long sum=0;
        unordered_map<int, int>map;
        while(j<n){
            if(map[nums[j]]>0){
                while(map[nums[j]]>0){
                    map[nums[i]]--;
                    sum-=nums[i];
                    i++;
                }
            }
            if((j-i+1)>k){
                map[nums[i]]--;
                sum-=nums[i];
                i++;
            }

            map[nums[j]]++;
            
            sum+=nums[j];
            if((j-i+1)==k){
                ans=max(ans,sum);
            }
            j++;
        }
        return ans;
    }
};