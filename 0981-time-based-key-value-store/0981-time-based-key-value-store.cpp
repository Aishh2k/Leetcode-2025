class TimeStamp {
public:
    int time;
    string value;
    TimeStamp(int t, string v) {
        time = t;
        value = v;
    }
};
class TimeMap {
public:
    unordered_map<string, vector<TimeStamp>> mp;
    void set(string key, string value, int timestamp) {
        TimeStamp t(timestamp, value);
        mp[key].push_back(t);
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        } else {
            vector<TimeStamp>& vec = mp[key];
            int l = 0;
            int h = vec.size() - 1;
            int res = -1;

            while (l <= h) {
                int m = l + (h - l) / 2;
                if (vec[m].time <= timestamp) {
                    res = m;
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
            if(res == -1){
                return "";
            }
            return vec[res].value;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */