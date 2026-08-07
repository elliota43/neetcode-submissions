class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int, bool> seen{};

        for (auto num : nums) {
            if (seen[num]) 
                return true;

            seen[num] = true;            
        }

        return false;
    }
};