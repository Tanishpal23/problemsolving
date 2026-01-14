class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;

        for(int i=0; i<n; i++){

            int maxVal = nums[i] + k;
            cout << maxVal;

            int j = i;
            while( j<n && nums[j] <= maxVal  ){
                j++;
            }

            cnt++;
            i = j-1;
            
        }
        
        return cnt;
    }
};