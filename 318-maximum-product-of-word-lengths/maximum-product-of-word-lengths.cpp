// Approach
// 1.for every word make a no using a,b,c.... as bit 0,1,2,
// 2.then take bitwise and operation of each term
// 3.if bitwise and == 0, no matching (bit digit) -> no matching char

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<int> bitMask(n, 0);

        for(int i=0; i<n; i++){

            for(char c: words[i]){
                bitMask[i] |= (1<<(c-'a'));
            }
        }

        int ans = 0;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((bitMask[i] & bitMask[j]) == 0){
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }

        return ans;
    }
};