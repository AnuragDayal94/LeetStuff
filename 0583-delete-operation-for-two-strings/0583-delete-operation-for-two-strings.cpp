class Solution {
public:

    int solve(string a, string b){
        int m=a.length();
        int n=b.length();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(a[i]==b[j])dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        int n=solve(word1, word2);
        return (word1.length()-n)+(word2.length()-n);
    }
};