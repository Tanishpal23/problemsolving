// Approach
// 1. Compute XOR of all numbers from 1 to n+1.
// 2. Compute XOR of encoded[1], encoded[3], encoded[5]...
// 3. First element of perm = step1 XOR step2.
// 4. Use consecutive XOR to rebuild the full permutation.

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();

        int xr1 = 0;
        for(int i=0; i<=n; i++){
            xr1^=(i+1);
        }

        int xr2 = 0;
        for(int i=0; i<n; i+=2){
            xr2^=(encoded[i+1]);
        }

        vector<int> ans(n+1, 0);
        ans[0] = xr1^xr2;

        for(int i=0; i<n; i++){
            ans[i+1] = ans[i]^encoded[i];
        }

        return ans;

    }
};