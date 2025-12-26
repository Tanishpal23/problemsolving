class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        int dupCount = 0;

        // Initial frequencies
        for (int x : nums) {
            freq[x]++;
            if (freq[x] == 2) dupCount++;  // becomes duplicate
        }

        if (dupCount == 0) return 0;

        int ops = 0;
        int i = 0;
        int n = nums.size();

        while (i < n) {
            ops++;

            // remove first 3 elements
            for (int j = 0; j < 3 && i < n; j++, i++) {
                int val = nums[i];
                if (freq[val] == 2) dupCount--; // duplicate resolved
                freq[val]--;
            }

            if (dupCount == 0) break;
        }

        return ops;
    }
};