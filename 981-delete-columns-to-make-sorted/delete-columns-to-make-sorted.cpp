//Approach
//Just traversal

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int ans = 0;
        for(int i=0; i<m; i++){
            bool is=false;
            for(int j=0; j<n-1; j++){
                if(strs[j][i]>strs[j+1][i]){
                    is=true;
                }
            }
            ans+=is;
        }

        return ans;
    }
};