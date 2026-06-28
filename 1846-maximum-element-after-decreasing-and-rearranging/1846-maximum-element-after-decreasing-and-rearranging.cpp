class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans=1;
        sort(arr.begin(),arr.end());
        for(int i=1; i<arr.size(); i++){
            if(abs(ans-arr[i]) >1)arr[i]=ans+1;

            ans=arr[i];
        }
        return ans;

    }
};