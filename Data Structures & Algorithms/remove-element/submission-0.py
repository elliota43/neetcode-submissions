class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        write_idx = 0

        for i in range(0, len(nums)):
            if nums[i] != val:
                nums[write_idx] = nums[i]
                write_idx += 1
            
        return write_idx