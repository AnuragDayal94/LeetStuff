class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        f={}

        for i,x in enumerate(nums):
            if (target-x in f):
                return (i,f[target-x])
            else:
                f[x]=i