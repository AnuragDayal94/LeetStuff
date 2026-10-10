class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        ans=(sum(nums[:k]))/k
        temp=sum(nums[:k])
        # print(temp)


        for i in range(k,len(nums)):
            temp=temp-nums[i-k]+nums[i]
            ans=max(ans, temp/k)
            # print(temp)


        return ans