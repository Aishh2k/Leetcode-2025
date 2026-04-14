class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // [0,1] -> 1->0
        // [2,1] -> 1->2
        // num courses = 3 : 0 1 2
        // 1 0 1
        // [a,b] -> b->a

        unordered_map<int, vector<int>> graph;
        vector<int> inD(numCourses, 0);

        for (auto p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            graph[prereq].push_back(course); // if i do 1 then i can do 0, 2
            inD[course]++;                   //
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inD[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        int taken = 0;

        while (!q.empty()) {
            int c = q.front();
            order.push_back(c);
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
            return order;
        } else {
            return {};
        }
    }
};