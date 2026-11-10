class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> graph; //if you take key -> [a,b,c,d] becomes available
        vector<int> inD(numCourses, 0);
        for(int i = 0;i<p.size();i++){
            int pre = p[i][1]; // prereq
            int c = p[i][0]; // course
            graph[pre].push_back(c);
            inD[c]++;
        }

        queue<int> no_preq;
        for(int i = 0;i<numCourses;i++){
            if(inD[i] == 0){
                no_preq.push(i);
            }
        }

        int finish = 0;

        while(!no_preq.empty()){
            finish++;
            int c = no_preq.front();
            no_preq.pop();

            for(auto nei: graph[c]){
                inD[nei]--;
                if(inD[nei] == 0){
                    no_preq.push(nei);
                }
            }
        }

        if(finish == numCourses){
            return true;
        }else{
            return false;
        }
        
    }
};