//Approach
//sieve

//Error -> only check for i*i<n, i checked for i<n -> integer overflow for i*i

//TC - O(n log log (n))
//SC - O(n)

class Solution {
public:

    int countPrimes(int n) {
        vector<bool> sieve(n+1, false);

        int cnt=0;

        for(int i=2; i*i<n; i++){

            if(sieve[i]==false){
                for(int j=i*i; j<=n; j+=i){
                    sieve[j] = true;
                }
            }
        }
        for(int i = 2; i < n; i++) {
            if(!sieve[i]) cnt++;
        }
        return cnt;
    }
};