class Solution:
    def firstUniqChar(self, s: str) -> int:
        f={}
        n=len(s)
        for x in range(0,n):
            f[s[x]]=f.get(s[x],0)+1

        for x in range(0,n):
            if(f[s[x]]==1):
                return x
        return -1