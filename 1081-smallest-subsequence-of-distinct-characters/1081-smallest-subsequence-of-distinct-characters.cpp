class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>vis(26);
        vector<int>count(26);
        string ans="";

        for(auto ch:s){
            count[ch-'a']++;
        }

        for(auto ch:s){
            if(!vis[ch-'a']){
                while(!ans.empty() && ans.back()>ch){
                    char temp=ans.back();
                    if(count[temp-'a']>0){
                        vis[temp-'a']=0;
                        ans.pop_back();
                    } else{
                        break;
                    }                   
                }
                ans.push_back(ch);
                vis[ch-'a']=1;
            }
            count[ch-'a']--;
        }
        return ans;
    }
};