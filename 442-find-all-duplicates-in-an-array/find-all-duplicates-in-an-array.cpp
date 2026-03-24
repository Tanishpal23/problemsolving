class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int sz = nums.size();

        vector<int> ans;
        for( int i=0; i<sz; i++ ){
            int ind = abs(nums[i]) - 1;

            if( nums[ind] < 0 ) ans.push_back( abs(nums[i]) );

            else nums[ind] = -nums[ind];
        }

        return ans;
    }
};