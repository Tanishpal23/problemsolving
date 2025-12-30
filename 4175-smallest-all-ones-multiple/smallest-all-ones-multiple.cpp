// Approach
// instead of adding only emplacing 1 always... we can take modulus with k also....
// i.e (num*10+1) ==== ((num*10+1)%k)

class Solution {
public:
    int minAllOneMultiple(int k) {
        if(!(k%2) || !(k%5)) return -1;
        int cnt = 0;
        int rem = 1;

        while(1){
            cnt++;
            if(rem%k == 0) return cnt;
            rem = (rem*10+1)%k;
        }

        return -1;
    }
};