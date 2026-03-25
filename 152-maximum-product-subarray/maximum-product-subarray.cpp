class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int sz = nums.size();
        int prefixProd = 1;
        int suffixProd = 1;

        int maxi = INT_MIN;

        for( int i=0; i<sz; i++ ){
            if( !prefixProd ) prefixProd = 1;
            if( !suffixProd ) suffixProd = 1;

            prefixProd *= (nums[i]);
            suffixProd *= (nums[sz-i-1]);

            maxi = max( { maxi, prefixProd, suffixProd } );
        }

        return maxi;
    }
};