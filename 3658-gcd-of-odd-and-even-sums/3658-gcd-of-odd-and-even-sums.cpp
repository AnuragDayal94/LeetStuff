class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long a=n*n;
        long long b=a+n;

        while(a>0 && b>0){
            if(a>b){
                a=a%b;
            }else{
                b=b%a;
            }
        }
        return a+b;
    }
};