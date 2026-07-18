class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)){
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, val] = q.front();
            q.pop();

            if(word == endWord){
                return val;
            }

            for(int i = 0;i<word.size();i++){
                string temp = word;
                for(int j =0;j<26;j++){
                    temp[i] = 'a' + j;
                    if(st.count(temp)){
                        st.erase(temp);
                        q.push({temp, val+1});
                    }
                }
            }
        }
        return 0;
        
        
    }
};