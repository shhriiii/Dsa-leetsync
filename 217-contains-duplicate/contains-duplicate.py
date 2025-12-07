class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mp = {}
        n = len(nums)
        for x in nums:
            mp[x] = mp.get(x,0)+1

        for key in mp:
            if mp[key] > 1 :
                return True
        
        return False
        