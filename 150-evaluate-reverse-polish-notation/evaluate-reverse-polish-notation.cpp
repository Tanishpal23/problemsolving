class Solution {
public:

    bool ifOperator( string& s ){
        return (s == "/" || s == "*" || s == "-" || s == "+" );
    }

    int findVal( int& a, int& b, string op ){
        if( op == "+" ) return a+b;
        else if( op == "-" ) return a-b;
        else if( op == "*" ) return a*b;
        return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        int n = tokens.size();

        stack<int> st;

        for( auto c: tokens ){
            if( ifOperator( c ) ){
                int sec = st.top(); st.pop();
                int fir = st.top(); st.pop();
                int cr = findVal( fir, sec, c );

                st.push( cr );
            }
            else st.push( stoi( c ) );
        }

        return st.top();
    }
};