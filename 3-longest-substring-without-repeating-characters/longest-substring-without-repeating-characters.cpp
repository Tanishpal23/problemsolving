class Solution {
public:
    int n;

    int findAns( string s ){
        int r = 0;
        int l = 0;
        unordered_map<char, int> mpp; //last seen of the index

        int ans = 0;
        while( r<n ){
            if( mpp.find(s[r]) == mpp.end() || mpp[s[r]] < l ){
                mpp[s[r]] = r;
                ans = max( ans, r-l+1 );
                r++;
            }
            else l = mpp[s[r]] + 1;
        }

        return ans;
    }
    int lengthOfLongestSubstring(string s) {
        n = s.size();

        return findAns(s);
    }
};