// Approach
// Sort
// teams -> first+last, second+second last.. and so on..

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        
        int n = skill.size();
        int m = n/2;
        sort(skill.begin(), skill.end());

        int skl = skill[0]+skill[n-1];

        for(int i=0; i<m; i++){
            if( skill[i] + skill[n-i-1] == skl ){
                ans += (1ll*skill[i]*skill[n-i-1]);
            }else return -1;
        }

        return ans;

    }
};