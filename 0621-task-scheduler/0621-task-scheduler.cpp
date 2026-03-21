class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for (char c : tasks) {
            mp[c]++;
        }

        int res = 0;

        priority_queue<int> pq;

        for (auto i : mp) {
            pq.push(i.second);
        }

        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (int c : temp) {
                if(c>0){
                    pq.push(c);
                }
            }

            if (!pq.empty()) {
                res += n + 1;
            } else {
                res += temp.size();
            }
        }
        return res;
    }
};