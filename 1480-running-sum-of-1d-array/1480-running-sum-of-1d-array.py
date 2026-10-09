class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        ans=[]

        sum=0
        for x in nums:
            temp=sum+x
            ans.append(temp)
            sum=temp

        return ans