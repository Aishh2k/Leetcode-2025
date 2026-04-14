class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // [0,1] -> 1->0 
        // [2,1] -> 1->2
        // [a,b] -> b->a

        unordered_map<int,vector<int>> graph;
        vector<int> inD(numCourses,0);

        for(auto p : prerequisites){
            graph[p[1]].push_back(p[0]); //if i do 1 then i can do 0, 2
            inD[p[0]]++;
        }

        queue<int> q;
        for(int i =0;i<numCourses;i++){
            if(inD[i] == 0){
                q.push(i);
            }
        }
        int taken = 0;


        while(!q.empty()){
            int c = q.front();
            q.pop();
            taken++;

            for(int i: graph[c]){
                inD[i]--;
                if(inD[i] == 0){
                    q.push(i);
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