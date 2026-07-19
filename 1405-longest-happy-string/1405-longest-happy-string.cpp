class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a) {
            pq.push({a, 'a'});
        }
        if (b) {
            pq.push({b, 'b'});
        }
        if (c) {
            pq.push({c, 'c'});
        }

        string ans = "";

        while (!pq.empty()) {
            auto [count, c] = pq.top();
            pq.pop();

            if (ans.size() >= 2 && ans[ans.size() - 1] == c &&
                ans[ans.size() - 2] == c) {
                if (pq.empty()) {
                    break;
                } else {
                    auto [val, a] = pq.top();
                    pq.pop();
                    ans += a;
                    val--;
                    if (val > 0) {
                        pq.push({val, a});
                    }

                    pq.push({count, c});
                }
            } else {
                ans += c;
                count--;
                if (count > 0) {
                    pq.push({count, c});
                }
            }
        }

        if (!pq.empty()) {
            return "";
        } else {
            return ans;
        }
    }
};