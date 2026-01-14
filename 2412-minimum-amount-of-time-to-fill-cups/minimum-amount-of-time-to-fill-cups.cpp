class Solution {
public:
    int fillCups(vector<int>& amount) {

        int ans = 0;
        bool flg = true;
        if( !amount[0] && !amount[1] && !amount[2] ) flg = false;

        while(flg){
            sort(amount.rbegin(), amount.rend());
            amount[0] = max(0, --amount[0]);
            amount[1] = max(0, --amount[1]);
            ans++;
            if( !amount[0] && !amount[1] && !amount[2] ) flg = false;
        }

        return ans;
        

        
    }
};