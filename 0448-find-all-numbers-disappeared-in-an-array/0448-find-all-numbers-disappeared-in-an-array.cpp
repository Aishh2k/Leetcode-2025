class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        vector<int> count(n+1 , 0);
        for(int i =0;i<nums.size();i++){
            count[nums[i]]++;
        }

        for(int i= 1;i<count.size();i++){
            if(count[i] ==0){
                res.push_back(i);
            }
        }


        return res;
        
    }
};