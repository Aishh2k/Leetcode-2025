class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inD(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for (auto i : prerequisites) {
            graph[i[1]].push_back(i[0]);
            inD[i[0]]++;
        }

        queue<int> q;

        for(int i =0;i<numCourses;i++){
            if(inD[i]==0){
                q.push(i);
            }
        }

        int taken = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            taken++;

            for(int nei: graph[course]){
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