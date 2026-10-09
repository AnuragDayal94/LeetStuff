class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        c=0
        arr=[]
        for x in nums:
            if(x==0):
                c+=1
            else:
                arr.append(x)
        
        j=0
        for i,x in enumerate(arr):
            nums[i]=x
            j=j+1

        while(c>0):
            nums[j]=0
            j+=1
            c-=1