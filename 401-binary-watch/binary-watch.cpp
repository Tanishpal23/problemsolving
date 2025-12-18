//Approach
//1. use recursion - (more complex code)
//2. check every time - hr and minute - if pop_count(h) + pop_count(min) == turnedOn, then push to ans with some condition.

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                if(__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    if(m < 10) time += "0";
                    time += to_string(m);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};
