class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int counts[26] = {0};

        for (size_t i{}; i < s.size(); ++i) {
            counts[s.at(i)-'a']++;
            counts[t.at(i)-'a']--;
        }

        for (size_t i{}; i < 26; ++i) {
            if (counts[i] != 0) return false;
        }

        return true;
    }
};
