// Approach 
// Calculate minimum across costBoth , cost1+cost2... take one of them for min(need1, need2)
// Calculate minimum across cost1, costBoth... assign for remaining need1
// Calculate minimum across cost2, costBoth... assign for remaining need2

// Error -> Integer overflow -> to eliminate always use 
// 1ll*(int)*(int) while multipling

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (!need1 && !need2) return 0;

        long long ans = 0;

        int common = min(need1, need2);

        int mini1 = min(costBoth, cost1 + cost2);
        ans += 1LL * mini1 * common;

        int mini2 = min(cost1, costBoth);
        ans += 1LL * mini2 * (need1 - common);

        int mini3 = min(cost2, costBoth);
        ans += 1LL * mini3 * (need2 - common);

        return ans;
    }
};
