class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<vector<int>> buckets(nums.size() + 1);
        vector<int> results;

        for (int num : nums) {
            counts[num]++;
        }

        for (auto [num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int num : buckets[i]) {
                results.push_back(num);
                if (results.size() == k) return results;
            }
        }

        return results;
    }
};
