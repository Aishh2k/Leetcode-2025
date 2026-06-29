class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;
        int l = 0;
        int r = people.size()-1;
        int sum;

        while(l<=r){
            if(l==r){
                sum = people[l];
                l++;
            }else{
                sum = people[l]+ people[r];
            }

            if(sum>limit){
                r--;
            }else{
                r--;
                l++;
            }
            count++;
        }
        return count;  
    }
};