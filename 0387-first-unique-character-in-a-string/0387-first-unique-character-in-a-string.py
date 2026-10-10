class Solution:
    def firstUniqChar(self, s: str) -> int:
        f={}
        for ch in s:
            f[ch]=f.get(ch,0)+1

        ans=-1
        for i,x in enumerate(s):
            if(f[x]==1):
                ans=i
                break
        return ans