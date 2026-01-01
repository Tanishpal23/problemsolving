// Approach
// like sum we can use Xor 
// keep prefixXor -> XOR of all element till that index
// like sum -> of l to r -> sum[r]-sum[l-1] => use same for XOR
// take one index more to avoid overflow


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> prefixXr(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefixXr[i + 1] = prefixXr[i] ^ arr[i];
        }

        vector<int> ans;
        for(auto &q : queries){
            int L = q[0];
            int R = q[1];

            ans.push_back(prefixXr[R + 1] ^ prefixXr[L]);
        }

        return ans;
    }
};
