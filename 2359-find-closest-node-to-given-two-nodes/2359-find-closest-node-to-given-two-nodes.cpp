class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1(edges.size(), -1);
        vector<int> dist2(edges.size(), -1);
        int dist = 0;
        int i = node1;
        do {
            dist1[i] = dist;
            dist++;
            i = edges[i];
        } while (i != -1 && dist1[i] == -1);

        dist = 0;
        i = node2;
        do {
            dist2[i] = dist;
            dist++;
            i = edges[i];
        } while (i != -1 && dist2[i] == -1);

        int maxd = 0;
        int index = -1;
        int mindist = INT_MAX;

        for (int i = 0; i < edges.size(); i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                maxd = max(dist1[i], dist2[i]);
                if(maxd < mindist){
                    index = i;
                    mindist = maxd;
                }
            }
        }
        return index;
    }
};

/*

2 2 3 -1
0 1 2 3

*/