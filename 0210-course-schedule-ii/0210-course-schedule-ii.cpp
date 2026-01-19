class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inD(numCourses,0);

        for(auto i: prerequisites){
            graph[i[1]].push_back(i[0]);
            inD[i[0]]++;
        }

        queue<int> q;
        int taken = 0;

        for(int i =0;i<numCourses;i++){
            if(inD[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            taken++;

            ans.push_back(course);
            for(int nei: graph[course]){
                inD[nei]--;
                if(inD[nei]==0){
                    q.push(nei);
                }
            }
        }
        if(taken == numCourses){
            return ans;
        }else{
            return {};
        }
        
        
    }
};