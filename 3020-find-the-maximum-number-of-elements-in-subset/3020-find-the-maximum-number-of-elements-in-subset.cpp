class Solution {
public:

    long long mod=1e9+7;

    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(auto num:nums){
            map[num]++;
        }
        
        int ans=1;

        for(auto i:map){
            if(i.first==1){
                if(i.second&1)ans=max(ans,i.second);
                else ans=max(ans,i.second-1);
            }else{
                int count=0;
                long long curr=i.first;
                while(map.find(curr)!=map.end()){
                    if(map[curr]>=2)count+=2;
                    else{
                        count++;
                        ans=max(ans,count);
                        count=0;
                    }
                    curr=(curr*curr)%mod;
                }
                ans=max(ans,count);
                if((ans&1)==0)ans--;
            }
            
        }
        return ans;
    }
};