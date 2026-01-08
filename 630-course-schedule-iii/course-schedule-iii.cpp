// Approach
// Sort the courses according to lastDay
// Maintain a pq to find the largest duration course
// If currTime + duration crosses lastDay, remove the largest duration course from the pq.
// Return size of pq

class Solution {

    //Comparator
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }


public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        //Sorting the courses with respect to lastDay
        sort(courses.begin(), courses.end(), cmp);

        //Pq declaration
        priority_queue<int> pq;
        int currTime = 0;

        //process all courses
        for(auto& c: courses){
            int dur = c[0];
            int lastDay = c[1];

            //currTime -> after taking curr course
            currTime += dur;
            pq.push(dur);

            //currTime > lasteDay -> removes the course with longest days
            if(currTime > lastDay){
                currTime -= pq.top();
                pq.pop();
            }
        }

        //return size of pq
        return pq.size();
    }
};