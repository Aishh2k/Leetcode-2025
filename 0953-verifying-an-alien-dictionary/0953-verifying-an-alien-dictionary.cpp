class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dic(26, 0);

        for (int i = 0; i < order.size(); i++) {
            dic[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string first = words[i];
            string second = words[i + 1];
            bool difference = false;
            int l = min(first.size(), second.size());

            for (int j = 0; j < l; j++) {
                if (first[j] != second[j]) {
                    difference = true;
                    if (dic[first[j] - 'a'] > dic[second[j] - 'a']) {
                        return false;
                    }
                    break; // only check the first different chars
                }
            }
            if (!difference && first.size() > second.size()) {
                return false;
            }
        }
        return true;
    }
};