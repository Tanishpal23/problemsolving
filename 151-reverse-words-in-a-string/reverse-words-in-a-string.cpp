class Solution {
public:
    string reverseWords(string s) {
        
        int r = s.size()-1;

        string ans = "";

        while( r>=0 ){
            if( isalnum(s[r]) ){
                int l = r-1;
                while( l>=0 && isalnum(s[l]) ) l--;
                ans += s.substr( l+1, r-l );

                cout << s.substr( l+1, r-l) << endl;

                ans += ' ';
                r = l-1;
            }
            else r--;
        }

        ans.pop_back();
        return ans;

    }
};