class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        unordered_map<char,int>map;
        int ans=0;

        while(j<s.size()){
            if(map[s[j]]>=1){
                ans=max(ans,(j-i));
                while(map[s[j]]>0){
                    map[s[i]]--;
                    i++;
                }
            }

            map[s[j]]++;
            j++;
        }

        ans=max(ans,(j-i));
        return ans;
    }
};