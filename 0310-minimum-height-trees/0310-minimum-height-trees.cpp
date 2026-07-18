class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n ==1){
            return {0};
        }
        
        unordered_map<int, vector<int>> graph;
        vector<int> degree(n, 0);

        for(auto e: edges){
            graph[e[1]].push_back(e[0]);
            graph[e[0]].push_back(e[1]);

            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i =0;i<n;i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }
        
        int rem = n;

        while(rem > 2){
            int leaves = q.size();
            rem -= leaves;

            for(int i =0;i<leaves;i++){
                int leaf = q.front();
                q.pop();

                for(int nei : graph[leaf]){
                    degree[nei]--;
                    if(degree[nei] == 1){
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};