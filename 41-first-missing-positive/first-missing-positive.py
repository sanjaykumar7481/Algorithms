def fun(ans,r,i):
        if i==len(r):
            return ans
        elif(ans!=r[i]):
            return ans
        else:
            return fun(ans+1,r,i+1)
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        ans=1 
        r=[]
        for i in nums:
            if(i>0):
                r.append(i)
        r.sort()
        r=list(set(r))
        r.sort()
        if(r==[]):
            return 1
        s=fun(ans,r,0)
        return s