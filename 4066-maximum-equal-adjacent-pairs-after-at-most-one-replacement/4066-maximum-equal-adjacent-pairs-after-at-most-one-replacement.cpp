class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int a=0;
        int b=0;
        map<pair<int,int>, int>m;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1])a++;
            else{
                m[{nums[i], nums[i-1]}]++;
                m[{nums[i-1], nums[i]}]++;

            }
        }

        for(auto  it:m){
            b=max(b, it.second);
        }
        return a+b;
    }
};