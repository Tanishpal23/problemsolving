class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;
        for (int j = i; j < nums.size(); j++) {
            if (used.count(nums[j])) continue;
            used.insert(nums[j]);

            swap(nums[i], nums[j]);
            solve(i + 1, nums);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};
