class Solution {
public:

    bool isPalindrome(string& s,int i,int j){
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string & s,int j,int index,vector<vector<int>>& dp){
        //base case : 
        if(index >= s.size()){
            if(j >= s.size()){
                return 0;
            }
            else{
                return INT_MAX;
            }
        }

        if(dp[j][index] != -1){
            return dp[j][index];
        }
        //case 1 : 
        int ans1 = INT_MAX;
        if(isPalindrome(s,j,index) == true){
            // cout<<"HI"<<endl;
            ans1 = 1 + solve(s,index+1,index+1,dp);
        }

        //case 2 :
        int ans2 = solve(s,j,index+1,dp);

        return dp[j][index] = min(ans1,ans2);
    }
    int minCut(string s) {
        int index = 0;
        int j = 0;
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1)); 
        int ans = solve(s,j,index,dp);
        return ans-1;
    }
};