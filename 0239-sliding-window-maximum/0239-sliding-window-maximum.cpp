class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i =0;i<k;i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()]){ 
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[dq.front()]);

        for(int i =k;i<nums.size();i++){
            while(!dq.empty() && dq.front()<=i-k){ // validity of window
                dq.pop_front();
            }

            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(!dq.empty()){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
        
    }
};