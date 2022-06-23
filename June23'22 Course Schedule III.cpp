class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        if(v1[1] != v2[1]) return v1[1] < v2[1];
        return v1[0]<v2[0];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        sort(courses.begin(), courses.end(), cmp); // sorting acc to lastDay
        int currentTime= 0;// the current ending time of a course.
        
        for(auto it: courses){
            int duration= it[0];
            int lastDay= it[1];
            
            currentTime+= duration; // addding the current duration to currentTime
            pq.push(duration); // pushing the duration in pq.
            
            if(currentTime > lastDay) {
                int largestDuration = pq.top(); pq.pop();
                // decreaing the largest duration course till now including the curent one as we have already pushed it into the pq --> so as to get the min currentTime so that we can include max courses.
                currentTime-= largestDuration;
            }
        }
      
        return pq.size();
    }
};
