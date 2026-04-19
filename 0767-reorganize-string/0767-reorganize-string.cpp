class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(int i =0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto a: mp){
            pq.push(make_pair(a.second, a.first));
        }
        if(!pq.empty()){
            auto a = pq.top();
            if(a.first>(s.size() +1)/2){
                return "";
            }
        }
        string ans = "";
        pair<int, char> temp;
        temp.first = -1;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ans += p.second;
            if(temp.first>0){
                pq.push(temp);
            }
            temp.first = --p.first;
            temp.second = p.second;
        }
        return ans;
    }
};