// Approach
// like sum we can use Xor 
// keep prefixXor -> XOR of all element till that index
// like sum -> of l to r -> sum[r]-sum[l-1] => use same for XOR


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> prefixXr(n, 0);

        for(int i = 0; i < n; i++){
            if(i==0){
                prefixXr[i]=arr[i];
                continue;
            }
            prefixXr[i] = prefixXr[i-1] ^ arr[i];
        }

        vector<int> ans;
        for(auto &q : queries){
            int L = q[0];
            int R = q[1];

            if(L==0){
                ans.push_back(prefixXr[R]);
                continue;
            }
            ans.push_back(prefixXr[R] ^ prefixXr[L-1]);
        }

        return ans;
    }
};
