// Approach
// Brute Force

class Solution {

    int n;
    int m;

    bool isSequence(int st, int end, vector<int>& nums){
        
        int m = end-st+1;

        vector<int> temp(nums.begin()+st, nums.begin()+end+1);
        sort(temp.begin(), temp.end());
        
        int dif = temp[1]-temp[0];

        for(int i=0; i<m-1; i++){
            if( temp[i+1] - temp[i] != dif ) return false;
        }

        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        n = nums.size();
        m = l.size();

        vector<bool> ans;

        for(int j=0; j<m; j++){

            int left = l[j];
            int right = r[j];

            ans.push_back( isSequence(left, right, nums) );

        }

        return ans;
    }
};