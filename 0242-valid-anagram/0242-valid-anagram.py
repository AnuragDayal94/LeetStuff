class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        f={}
        f2={}

        for x in s:
            f[x]=f.get(x,0)+1
        for x in t:
            f2[x]=f2.get(x,0)+1

        for x in f:
            if (x not in f2 or f[x]!=f2[x]):
                return False
        return True