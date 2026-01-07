class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        string ans = s;

        int j=n-1;

        while(j>=0){
            if(s[j]=='2') break;
            else{
                ans.pop_back();
            }
            j--;
        }

        return ans;
    }
};