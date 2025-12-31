class Solution {
public:
    char findTheDifference(string s, string t) {

        int n = s.size();

        int st = 0;
        int ss = 0;

        for(int i=0; i<n; i++){
            st+=(t[i]);
            ss+=(s[i]);
        }
        st+=t[n];

        return (char)(st-ss);
    }
};