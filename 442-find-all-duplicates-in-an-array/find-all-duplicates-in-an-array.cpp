// Approach
// Mark curr element's index -curr element -> if element = 5, marks nums[4] = -nums[4]
// Now if curr element is already negative that means someone else is present before 
// hence repeating.

// TC O(n)
// SC O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;
        int n = nums.size();

        for(auto num: nums){

            //index that needs to make negative
            int ind = abs(num) - 1;

            //if already negative -> present before
            if( nums[ind] < 0 ){
                ans.push_back(abs(num));
            }
            //else make it negative
            else{
                nums[ind] = -nums[ind];
            }
        }

        //return ans
        return ans;
    }
};