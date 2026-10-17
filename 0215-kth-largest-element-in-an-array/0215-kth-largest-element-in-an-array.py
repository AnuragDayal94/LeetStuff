class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        import heapq
        p=[]
        for i, x in enumerate(nums):
            heapq.heappush(p,-x)

        ans=0
        for i in range(0,k):
            ans=-heappop(p)
        return ans
