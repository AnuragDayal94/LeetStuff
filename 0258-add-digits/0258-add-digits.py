class Solution:
    def addDigits(self, nums: int) -> int:
        while(nums>=10):
            temp=0
            while(nums>0):
                temp=temp+nums%10
                nums=nums//10
            nums=temp
        return nums
