class Solution {
public:
    string countAndSay(int n) {
        
        string ans = "1";
        for( int i=0; i<n-1; i++ ){

            string temp = "";
            int l = 0;
            
            int n1 = ans.size();

            while( l<n1 ){
                int cnt = 1;
                while( l<n1-1 && ans[l]==ans[l+1] ){
                    cnt++;
                    l++;
                }
                temp += (to_string(cnt) + ans[l]);
                l++;
            }

            ans = temp;
            

        }

        return ans;
    }
};