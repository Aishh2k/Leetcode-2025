class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int>mp;

        for(char c: s){
            mp[c]++;
        }

        for(auto i: mp){
            pq.push({i.second, i.first});
        }

        string ans = "";
        pair<int, char> temp;

        while(!pq.empty()){
            auto [v, c] = pq.top();
            pq.pop();
            ans += c;

            if(temp.first>0){
                pq.push({temp.first, temp.second});
            }

            temp.first = --v;
            temp.second = c;
        }

        if(temp.first>0){
            return "";
        }else{
            return ans;
        }
    }
};