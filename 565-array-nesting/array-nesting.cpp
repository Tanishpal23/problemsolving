// Approach
// check for all indices

// Observation
// One index can only contribute towards one chain.
// So use unvisited array -> make chains -> when chains ends -> make new chain.

// TC - O(n)
// SC - O(n)

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();

        //maxCnt
        int maxCnt = 0;
        int cnt = 0;
        int curr = -1;

        vector<bool> vis(n, false);

        for(int i=0; i<n; i++){
            
            //if curr i is unvisited -> no chain of this element is made yet
            if( !vis[i] ){

                //mark visited, cnt, curr
                vis[i] = true;
                cnt = 1;
                curr = i;

                //make chain
                while( !vis[nums[curr]] ){
                    //mark chain element, update cnt, curr
                    vis[nums[curr]] = true;
                    cnt++;
                    curr = nums[curr];
                }

                //update maxCnt
                maxCnt = max(maxCnt, cnt);
            }
        }
        
        //return ans
        return maxCnt;
    }
};