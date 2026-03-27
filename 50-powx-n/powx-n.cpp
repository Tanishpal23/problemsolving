class Solution {
public:

    double findAns( double x, long long n ){

        if( n==0 ) return 1;
        else if( n==1 ) return x;

        if( n%2 ) return x * findAns( x, n-1 );
        return findAns( x*x, n/2 );

    }
    double myPow(double x, int n) {

        long long k = 1ll*n;

        if( k<0 ) return 1.0/findAns( x, -k );
        return findAns( x, k );

    }
};