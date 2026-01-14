class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        int ans = 0;

        sort(cost.rbegin(), cost.rend());
        for(int i=0; i<n; i+=3){
            int c1 = cost[i];
            int c2 = (i+1<n)? cost[i+1]: 0;
            ans += (c1+c2);
        }
        return ans;
    }
};