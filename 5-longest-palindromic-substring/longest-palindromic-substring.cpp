class Solution {
public:

    int n;
    int start = 0;
    int maxLen = 0;

    void findInd(string s, int l, int r){

        while( l>=0 && r<n && s[l]==s[r] ){
            l--;
            r++;
        }

        int len = r-l-1;
        if( len > maxLen ){
            start = l+1;
            maxLen = len;
        }

        return;
    }
    string longestPalindrome(string s) {
        
        n = s.size();

        for( int i=0; i<n; i++ ){
            findInd( s, i, i );
            findInd( s, i, i+1 );
        }

        return s.substr( start, maxLen );

    }
};