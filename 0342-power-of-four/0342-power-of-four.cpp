class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0)return false;
        int ans=0;
        for(int i=0; i<32; i++){
            if(((n>>i)&1)==1){
                ans=i;
                break;
            }
        
        }
        if(ans%2==0 && (n&(n-1))==0)return true;

        return false;
    }
};