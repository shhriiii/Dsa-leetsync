class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        mp = {}
        for x in nums:
            mp[x] = mp.get(x,0) + 1
        ans = []
        for key in mp:
            if mp[key] > n//3:
                ans.append(key)
        return ans
        