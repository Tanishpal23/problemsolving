//approach
//1. count no of plants between each pair of seats
//2. multiply all (plants+1).
//3. check if count is even or odd. odd- division not possible

class Solution {
public:

    const long MOD = 1e9+7;

    int numberOfWays(string corridor) {
        long ans = 1;
        int seatCount = 0;
        int plantCount = 0;

        for(char c: corridor){
            if(c=='S'){
                seatCount++;

                if(seatCount>2){
                    ans=(ans*(plantCount+1))%MOD;

                    seatCount = 1;
                    plantCount = 0;

                }
            }else{
                if(seatCount == 2){
                    plantCount++;
                }
            }
        }

        if(seatCount!=2) return 0;
        return (int)ans;
    }
};