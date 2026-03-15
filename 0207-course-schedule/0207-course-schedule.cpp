class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector < vector<int>> graph(numCourses);
        vector<int> inD(numCourses, 0); // number of preq for each course
                                        // b->a (a,b)
        for (auto c : p) {
            graph[c[1]].push_back(c[0]); // graph[c] courses that becomes
                                         // available after you take c
            inD[c[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (inD[i] == 0) {
                q.push(i); // b;
            }
        }

        int taken = 0;

        while(!q.empty()){
            int c = q.front();
            q.pop();
            taken++;
            for(int nei: graph[c]){
                inD[nei]--;
                if(inD[nei]==0){
                    q.push(nei);
                }
            }
        }

        if(taken == numCourses){
            return true;
        }else{
            return false;
        }
    }
};