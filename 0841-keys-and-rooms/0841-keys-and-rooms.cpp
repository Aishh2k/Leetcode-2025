class Solution {
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<bool>& visited){
        if(visited[i] == true){
            return;
        }

        visited[i] = true;
        for(int keys : rooms[i]){
            dfs(keys, rooms, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(0, rooms, visited);

        for(bool a : visited){
            if(a == false){
                return false;
            }
        }
        return true;

    }
};