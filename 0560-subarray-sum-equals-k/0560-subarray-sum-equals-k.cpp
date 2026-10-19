class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1; i<n; i++){
            pre[i]=nums[i]+pre[i-1];
        }

        unordered_map<int, int>map;
        for(int i=0; i<n; i++){
            if(pre[i]==k){
                ans++;                
            }

            if(map.find(pre[i]-k)!=map.end()){
                ans+=map[pre[i]-k];
            }
            map[pre[i]]++;
        }
        return ans;
    }
};