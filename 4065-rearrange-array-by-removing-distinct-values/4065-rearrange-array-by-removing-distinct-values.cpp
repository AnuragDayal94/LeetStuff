class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int >ans;
        map<int, int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        while(ans.size()<=nums.size()){
            if(ans.size()==nums.size())break;
            for(auto it:m){
                if( m[it.first]>0){
                    ans.push_back(it.first);
                    m[it.first]--;
                    
                }
            }
            // sort(ans.begin(), ans.end());
        }
        return ans;
    }
};