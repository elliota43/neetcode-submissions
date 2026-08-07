class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        seen.reserve(nums.size());

        for (int i{}; i < nums.size(); ++i) {
            int want = target - nums[i];

            if (auto it = seen.find(want); it != seen.end()) {
                return {it->second, i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};
