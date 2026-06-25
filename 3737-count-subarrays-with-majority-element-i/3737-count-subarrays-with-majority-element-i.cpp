class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target)count++;
            nums[i]=count;
        }
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                if(i==0){
                    if(nums[j]>(j+1)/2)ans++;
                }else{
                    if((nums[j]-nums[i-1])>(j-i+1)/2)ans++;

                }
            }
        }
        return ans;
    }
};