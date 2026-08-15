from collections import defaultdict

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        seen = defaultdict(int)

        for num in nums:
            seen[num] += 1

        for num, count in seen.items():
            if count > (len(nums) // 2):
                return num