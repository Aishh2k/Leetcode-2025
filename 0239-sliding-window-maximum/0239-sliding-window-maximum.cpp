class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int>res;

        for(int i =0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back(); // 3 -1
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]); // 3

        for(int i =k;i<nums.size();i++){
            while(!dq.empty() && dq.front()<=i-k){ // window validity
                dq.pop_front();
            }

            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            if(!dq.empty()){
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
        
    }
};