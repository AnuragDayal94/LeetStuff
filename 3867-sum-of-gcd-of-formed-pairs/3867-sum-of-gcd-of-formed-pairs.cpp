class Solution {
public:

   long long gcd(long long a, long long b){
    while(b){
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

    long long gcdSum(vector<int>& nums) {
        vector<long long>prefixgcd;
        int maxi=nums[0];
        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
            prefixgcd.push_back(gcd(nums[i],maxi));
        }

        sort(prefixgcd.begin(),prefixgcd.end());

        long long s=0;
        long long e=prefixgcd.size()-1;

        long long ans=0;
        while(s<e){
            ans+=gcd(prefixgcd[s],prefixgcd[e]);
            s++;
            e--;
        }
        return ans;

    }
};