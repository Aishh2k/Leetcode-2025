class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        vector<int> count(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busy;

        for (int i = 0; i < meetings.size(); i++) {
            while (!busy.empty() && busy.top().first <= meetings[i][0]) {
                auto [end, room] = busy.top();
                busy.pop();
                available.push(room);
            }

            if (available.size() > 0) {
                int room = available.top();
                available.pop();
                count[room]++;
                busy.push({meetings[i][1], room});
            } else {
                auto [end, room] = busy.top();
                busy.pop();
                long long newEnd = meetings[i][1] - meetings[i][0] + end;
                count[room]++;
                busy.push({newEnd, room});
            }
        }

        int ans = 0;
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                ans = i;
            }
        }
        return ans;
    }
};