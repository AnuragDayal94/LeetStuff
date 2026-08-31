class Solution {
public:

    int solve(vector<int> cuts, int i, int j, vector<vector<int>>&dp){
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans=INT_MAX;
        for(int k=i; k<=j; k++){
            ans=min(ans, cuts[j+1]-cuts[i-1]+solve(cuts, i, k-1, dp)+solve(cuts, k+1, j, dp));
        }
        if(ans==INT_MAX)return 0;
        return dp[i][j]=ans;
    }

    int tabulation(vector<int>&cuts){
        int m=cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));

        for(int i=m-2; i>=1; i--){
            for(int j=i; j<m-1; j++){
                int ans=INT_MAX;
                for(int k=i; k<=j; k++){
                    ans=min(ans, cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                }
                if(ans==INT_MAX)dp[i][j]= 0;
                else dp[i][j]=ans;
            }
        }
        return dp[1][m-2]; 
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        int m=cuts.size();
        // vector<vector<int>>dp(m+1, vector<int>(m+1,-1));
        // return solve(cuts, 1, m-2, dp);
        return tabulation(cuts);
    }
};