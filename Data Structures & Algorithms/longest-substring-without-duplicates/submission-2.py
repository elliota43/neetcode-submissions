class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        left = largest_sequence = 0 

        for right, char in enumerate(s):
            if char in seen and seen[char] >= left:
                left = seen[char] + 1

            seen[char] = right 

            current_len = right - left + 1 
            if current_len > largest_sequence:
                largest_sequence = current_len

        return largest_sequence