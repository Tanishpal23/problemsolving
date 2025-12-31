// Approach
// Take all XOR, as one element only once. XOR->ans

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for(char c: s){
            ans^=(c);
        }
        for(char c: t){
            ans^=(c);
        }

        return (char)(ans);
    }
};