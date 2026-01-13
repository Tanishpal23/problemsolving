//copied


class Solution {
    double eps = 1e-6;

    double findLowerSum(double y, vector<vector<int>>& squares) {
        double area = 0.0;

        for (auto &sq : squares) {
            double bottom = sq[1];
            double top = sq[1] + sq[2];
            double side = sq[2];

            if (y <= bottom) continue;                     // fully above line
            if (y >= top) area += side * side;             // fully below line
            else area += (y - bottom) * side;              // partially below
        }
        return area;
    }

    double findUpperSum(double y, vector<vector<int>>& squares) {
        double area = 0.0;

        for (auto &sq : squares) {
            double bottom = sq[1];
            double top = sq[1] + sq[2];
            double side = sq[2];

            if (y >= top) continue;                        // fully below line
            if (y <= bottom) area += side * side;          // fully above line
            else area += (top - y) * side;                 // partially above
        }
        return area;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {

        double left = 0.0, right = 1e9;
        double ans = 0.0;

        while (right - left > eps) {
            double mid = left + (right - left) / 2.0;

            double lowerSum = findLowerSum(mid, squares);
            double upperSum = findUpperSum(mid, squares);

            if (lowerSum >= upperSum) {
                ans = mid;
                right = mid;
            } else {
                left = mid;
            }
        }

        return ans;
    }
};
