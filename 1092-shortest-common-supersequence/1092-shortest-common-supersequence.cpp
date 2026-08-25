class Solution {
public:

    string solve(string s1, string s2){
        int m=s1.size();
        int n=s2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(s1[i]==s2[j])dp[i][j]=1+dp[i+1][j+1];
                else{
                    int a=dp[i+1][j];
                    int b=dp[i][j+1];

                    if(a<b){
                        dp[i][j]=b;
                    }else{
                        dp[i][j]=a;
                    }
                }
            }
        }
        
        string s="";
        int i=0; 
        int j=0;

        int len=m+n-dp[0][0];
        for(int z=0; z<len; z++){

            s+='#';
        }

        int index=0;

        while(i<m && j<n){
            if(s1[i]==s2[j]){
                s[index]=s1[i];
                index++;
                i++;
                j++;
            }else if(dp[i+1][j]>dp[i][j+1]){
                s[index]=s1[i];
                i++;
                index++;

            }else{
                s[index]=s2[j];
                j++;
                index++;
            }
        }
        while(i<m){
            s[index]=s1[i];
            i++;
            index++;
        }
        while(j<n){
            s[index]=s2[j];
            j++;
            index++;
        }
        return s;
    }

    string shortestCommonSupersequence(string s1, string s2) {
        return solve(s1,s2);
    }
};