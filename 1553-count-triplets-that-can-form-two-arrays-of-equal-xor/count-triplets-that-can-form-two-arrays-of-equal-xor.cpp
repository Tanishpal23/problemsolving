// Approach 
// Constraints->less ==== Brute force -> will work

// TC -> O(n^3)
// SC -> O(1)

// optimal
// 1. find two index i.............k
// 2. if xor of num[i]^num[i+1]..........num[k] == 0
// 3. then every split is possible from i to k
// 4. add (k-i)

// TC O(n^2)
// SC O(1)

// observation->
// A^B = 0 -> A=B <- at every index


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int xr = 0;
            for(int k = i; k < n; k++){
                xr ^= arr[k];
                if(xr == 0){
                    ans += (k - i);
                }
            }
        }
        return ans;
    }
};
