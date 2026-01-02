class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int, int> mpp;

        for(auto num: nums){
            mpp[num]++;
            if(mpp[num]==n/2) return num;
        }

        return -1;
    }
};