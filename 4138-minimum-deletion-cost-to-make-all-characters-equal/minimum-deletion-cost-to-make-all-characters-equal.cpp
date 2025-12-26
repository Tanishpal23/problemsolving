class Solution {
public:
    long long minCost(string s, vector<int>& cost) {

        int n = s.size();
        vector<long long> freq(26, 0);

        for(int i=0; i<n; i++){
            freq[s[i]-'a']+=cost[i];
        }
        
        long long ans = 0;
        long long maxi = 0;
        for(int i=0; i<26; i++){
            ans+=freq[i];
            maxi = max(maxi, freq[i]);
        }

        return ans-maxi;
    }
};