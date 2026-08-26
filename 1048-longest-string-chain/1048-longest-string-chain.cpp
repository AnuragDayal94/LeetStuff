class Solution {
public:

    bool solve(string& a, string& b){
        int m=a.size();
        int n=b.size();

        if((n-m)!=1)return false;

        int k=0;
        int i=0; int j=0;
        while(i<m && j<n){
            if(a[i]==b[j]){
                j++;
                i++;
            }else {
                k++;
                j++;
            }
        }

        if(k>1)return false;
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(),
             [](const string &a, const string &b) {
                 return a.size() < b.size();
             });

        vector<int>dp(n,1);
        vector<int>parent(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        int ans=1;
        int index=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                string a=words[j];
                string b=words[i];
                bool common=solve(a, b);
                if(common && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>ans){
                ans=dp[i];
                index=i;
            }
        }

        return ans;
    }
};