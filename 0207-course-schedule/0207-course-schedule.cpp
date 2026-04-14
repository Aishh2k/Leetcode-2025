class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // [0,1] -> 1->0
        // [2,1] -> 1->2
        // [0,3] -> 3->0
        // num courses = 3 : 0 1 2
                          // 1 0 1

        //q = 1

        unordered_map<int, vector<int>> graph;
        vector<int> inD(numCourses, 0);

        for (auto p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            graph[prereq].push_back(course); // if i do 1 then i can do 0, 2
            inD[course]++;                  
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inD[i] == 0) {
                q.push(i);
            }
        }
        int taken = 0;

        while (!q.empty()) {
            int c = q.front();
            q.pop();
            taken++;

            for (int i : graph[c]) {
                inD[i]--;
                if (inD[i] == 0) {
                    q.push(i);
                }
            }
        }

        if (taken == numCourses) {
            return true;
        } else {
            return false;
        }
    }
};