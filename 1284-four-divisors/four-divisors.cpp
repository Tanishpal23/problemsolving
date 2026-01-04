class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int ans = 0;
        for(int n: nums){
            
            vector<int> divisors;
            for(int i=1; i*i<=n; i++){
                if(n%i == 0){
                    divisors.push_back(i);
                    if( (n/i) != i ){
                        divisors.push_back(n/i);
                    }
                }
                if(divisors.size()>4) break;
            }

            if(divisors.size()==4){
                for(auto d: divisors){
                    ans+=d;
                }
            }
            divisors.clear();
        }

        return ans;
    }
};