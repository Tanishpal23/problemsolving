class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int sz = nums.size();

        vector<int> ans;
        unordered_set<int> stt;

        for( int i=0; i<sz; i++){

            if( stt.find( nums[i] ) != stt.end() ){
                ans.push_back( nums[i] );
            }
            stt.insert(nums[i]);
        }

        return ans;
    }
};