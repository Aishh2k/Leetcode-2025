class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto a: s){
            mp[a]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto i: mp){
            pq.push(make_pair(i.second, i.first));
        }

        if(!pq.empty()){
            auto a = pq.top();
            if(a.first > (s.size()+1)/2){
                return "";
            }
        }
        pair<int, char> temp;
        string res = "";
        
        while(!pq.empty()){
            pair<int, char> a = pq.top();
            pq.pop();
            res += a.second;

            if(temp.first>0){
                pq.push(temp);
            }
            temp = a;
            temp.first -=1;

        }


        return res;

    }
};