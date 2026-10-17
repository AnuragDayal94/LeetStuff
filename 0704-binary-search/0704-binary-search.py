class Solution:
    def search(self, nums: list[int], target: int) -> int:
        n=len(nums)

        s=0
        e=n-1
        ans=-1

        while(s<=e):
            m=(s+e)//2
            if(nums[m]==target):
                ans=m
                break
            elif(nums[m]<target):
                s=m+1
            else:
                e=m-1
        return ans