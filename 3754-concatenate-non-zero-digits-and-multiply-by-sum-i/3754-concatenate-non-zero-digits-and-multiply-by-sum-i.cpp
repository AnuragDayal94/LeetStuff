class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string z="";
        long long sum=0;
        for(int i=0; i<s.length(); i++){
            char ch=s[i];
            sum+=(ch-'0');
            if(ch!='0'){
                z+=ch;
            }
        }
        if(z.empty())return 0;
        long long x=stol(z);
        return x*sum;
    }
};