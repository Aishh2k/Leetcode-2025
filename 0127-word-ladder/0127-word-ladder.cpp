class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            auto [word, step] = q.front();
            q.pop();
             
            if(word == endWord){
                return step;
            }

            for(int i =0;i<word.size();i++){ // for every character in word
                char original = word[i];
                for(char c ='a'; c<= 'z';c++){
                    word[i] = c;
                    if(st.count(word)){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        return 0;
        
    }
};