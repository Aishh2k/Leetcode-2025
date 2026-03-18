class Solution {
public:
    int kSimilarity(string s1, string s2) {
        queue<pair<string, int>> q;
        q.push({s1,0});
        unordered_set<string> visited;
        visited.insert(s1);

        while(!q.empty()){
            auto [st, level] = q.front();
            q.pop();
            if(st == s2){
                return level;
            }

            int i =0;
            while(st[i] == s2[i]) i++;

            for(int j =i+1;j<st.size();j++){
                if(st[j] == s2[i]){
                    string next = st;
                    swap(next[i], next[j]);
                    if(!visited.count(next)){
                        visited.insert(next);
                        q.push({next, level+1});
                    }
                }
            }
        }

        return -1;
        
    }
};