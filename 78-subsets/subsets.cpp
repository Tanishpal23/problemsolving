class Solution {
public:

    int n;
    vector<vector<int>> ans;

    void findAllSubsets( vector<int>& nums, int i, vector<int> temp ){
        
        if( i>=n ){
            ans.push_back( temp );
            return;
        }
        //take
        temp.push_back( nums[i] );
        findAllSubsets( nums, i+1,  temp );

        //not take
        temp.pop_back();
        findAllSubsets( nums, i+1, temp );

        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        n = nums.size();
        findAllSubsets( nums, 0, {} );

        return ans;

    }
};