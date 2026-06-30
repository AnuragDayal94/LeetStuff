class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int r=0;
        int l=0;
        int ans=0;
        unordered_map<char,int>map;
        while(r<n){
            map[s[r]]++;
            if(map.size()==3){
                while(map[s[l]]>1){
                    map[s[l]]--;
                    l++;
                }
                ans+=l+1;

                // map[s[l]]--;
                // if(map[s[l]]==0)map.erase(s[l]);
                
                // l++;
            }
                r++;

            
        }
        return ans;
    }
};