// Approach
// sorted->BS

class Solution {
public:

    int findInd(vector<vector<int>>& grid, int row){
        int st = 0;
        int end = grid[row].size()-1;
        int ans = end+1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(grid[row][mid] < 0){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i=0; i<n; i++){
            int ind = findInd(grid, i);
            ans+=(m-ind);
        }
        return ans;
    }
};