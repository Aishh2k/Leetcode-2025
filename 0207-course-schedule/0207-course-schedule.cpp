class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> graph;
        vector<int> inD(numCourses, 0);

        for(auto i: p){
            graph[i[1]].push_back(i[0]);
            inD[i[0]]++;
        }

        queue<int> take;

        for(int i =0;i<numCourses;i++){
            if(inD[i] == 0){
                take.push(i);
            }
        }
        int finish = 0;
        while(!take.empty()){
            int a = take.front();
            take.pop();
            finish++;

            for(int i: graph[a]){
                inD[i]--;
                if(inD[i] == 0){
                    take.push(i);
                }
            }
        }

        if(finish == numCourses){
            return true;
        }

        return false;
        
    }
};