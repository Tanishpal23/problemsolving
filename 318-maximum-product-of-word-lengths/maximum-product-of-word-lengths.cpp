// Approach
// Brute Force

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        int ans = 0;

        for(int i=0; i<n-1; i++){
            unordered_map<char, int> mpp1;
            for(auto c: words[i]) mpp1[c] = 1;

            for(int j=i+1; j<n; j++){
                bool isPre = false;

                for(char c: words[j]){
                    if(mpp1.count(c)){
                        isPre = true;
                        break;
                    }
                }

                if(!isPre) ans = max(ans, (int)words[i].size()*(int)words[j].size());
            }
        }
        return ans;
    }
};