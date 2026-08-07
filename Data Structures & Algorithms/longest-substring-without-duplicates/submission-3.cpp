class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(128, -1);

        int l{};
        int longestSeen{};

        for (int r = 0; r < s.size(); ++r) {
            char currentChar = s[r];

            if (lastSeen[currentChar] >= l) {
                l = lastSeen[currentChar] + 1;
            }

            lastSeen[currentChar] = r;
            longestSeen = max(longestSeen, r - l + 1);
        }

        return longestSeen;
    }
};
