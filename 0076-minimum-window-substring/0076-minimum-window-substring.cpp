class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()) {
            return ("");
        }
        int n = s.size();
        int req = t.size();

        unordered_map<char, int> mp;

        for (char c : t) {
            mp[c]++;
        }

        int i = 0;
        int j = 0;

        int windowSize = INT_MAX;
        int start = 0;

        while(j<n){ // start expanding window
            char c = s[j];
            if(mp[c]>0){ // we got a required character 
                req--;
            }
            mp[c]--;

            while(req == 0){ // start shrinking window untill we remove somethign we needed
            if(j-i+1 <windowSize){
                windowSize = j-i+1;
                start = i;
            }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    req++;
                }
                i++;
            }
            j++;
        }

        return(windowSize == INT_MAX? "": s.substr(start, windowSize));

    }
};