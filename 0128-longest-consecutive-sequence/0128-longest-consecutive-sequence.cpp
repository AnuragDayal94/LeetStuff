class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int> map(nums.begin(), nums.end());

        int ans=0;
        for(auto num:map){
            if(map.find(num-1)==map.end()){
                int curr=num+1;
                int temp=1;
                while(map.find(curr)!=map.end()){
                    temp++;
                    curr++;
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};