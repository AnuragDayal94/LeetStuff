class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        arr=[0]

        s=0
        for x in gain:
            temp=s+x
            arr.append(temp)
            s=temp

        return max(arr)
