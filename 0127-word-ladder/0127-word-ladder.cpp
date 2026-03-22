class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(beginWord == endWord){
            return 1;
        }
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)){
            return 0;
        }

        queue<pair<string,int>>q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, step] = q.front();
            q.pop();

            if(word == endWord){
                return step;
            }
            for(int i =0;i<word.size();i++){
                string dup = word;
                for(char c ='a';c<='z';c++){
                    dup[i]=c;
                    if(st.count(dup)){
                        q.push({dup,step+1});
                        st.erase(dup);
                    }
                }
            }
        }

    return 0;
        
    }
};