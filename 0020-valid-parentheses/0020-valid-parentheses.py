class Solution:
    def isValid(self, s: str) -> bool:
        f={')':'(',']':'[','}':'{'}
        st=[]

        for ch in s:
            if(ch in ")}]"):
                if(len(st)>0 and st[-1]==f[ch]):
                    st.pop()
                else:
                    return False
            else:
                st.append(ch)
        return len(st)==0
