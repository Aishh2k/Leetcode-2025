class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        unordered_map<int, vector<int>> graph; // if you take a -> [b, c] becomes available
        vector<int> inD(numCourses,0);

        for(int i =0;i<p.size();i++){
            graph[p[i][1]].push_back(p[i][0]);
            inD[p[i][0]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inD[i] == 0){
                q.push(i);
            }
        }
        vector<int> res;

        while(!q.empty()){
            int c = q.front();
            q.pop();
            res.push_back(c);

            for(int i: graph[c]){
                inD[i]--;

                if(inD[i] == 0){
                    q.push(i);
                }
            }
        }

        if(res.size() == numCourses){
            return res;
        }else{
            return {};
        }
        
    }
};