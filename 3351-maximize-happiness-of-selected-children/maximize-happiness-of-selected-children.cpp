// Approach
// 1. Sort in descending order
// 2. Start taking greedly.
// 3. Stopping condition.

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());

        long long ans = 0;
        int cnt = 0;

        for(int i=0; i<n && i<k; i++){
            
            int curr = happiness[i] - cnt;

            if(curr<=0) break;
            ans+=curr;

            cnt++;
        }

        return ans;
    }
};