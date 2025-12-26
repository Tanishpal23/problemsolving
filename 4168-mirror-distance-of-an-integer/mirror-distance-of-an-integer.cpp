class Solution {
public:
    int findM(int n){
        int m = 0;
        while(n>0){
            m = m*10 + (n%10);
            n/=10;
        }

        return m;
    }
    int mirrorDistance(int n) {
        int m = findM(n);

        return abs(m-n);
    }
};