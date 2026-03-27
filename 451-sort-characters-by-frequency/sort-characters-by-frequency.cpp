class Solution {
public:
    string frequencySort(string s) {

        string ans = "";
        unordered_map< char, int > mpp;

        for( auto k: s ){
            mpp[k]++;
        }

        priority_queue<pair< int, char >> pq;
        for( auto& it: mpp ){
            char k = it.first;
            int freq = it.second;

            pq.push( {freq, k} );
        }

        while( !pq.empty() ){
            auto it = pq.top(); pq.pop();
            char k = it.second;
            int freq = it.first;

            ans += string( freq , k );

        }

        return ans;
    }
};