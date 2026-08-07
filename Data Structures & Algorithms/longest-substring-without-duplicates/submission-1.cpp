class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> seen(128, -1);

        int left{}, right{}, largestSequenceSeen{};

        while (right < s.size()) {
            char curr = s[right];

            if (seen[curr] >= left) left = seen[curr] + 1;

            seen[curr] = right;

            int currentSubstrLength = right - left + 1;
            largestSequenceSeen = std::max(currentSubstrLength, largestSequenceSeen);
            right++;
        }

        return largestSequenceSeen;
    }
};
