class Solution {
public:
    bool dfs(int i, int bucketNum, int curSum, int target, vector<int>& nums, vector<bool>& visited){
        if(bucketNum == 0){ // finished all buckets
            return true;
        }
        if(curSum == target){ // this bucket done, move to next
            return dfs(0,bucketNum-1, 0, target, nums, visited);
        }
        if(i>=nums.size()){ // cant reach element
            return false;
        }
        
        for(int j =i;j<nums.size();j++){
            if(visited[j] || (curSum + nums[j]) > target || (j>0 && nums[j] == nums[j-1]) && !visited[j-1]){
                continue;
            }
            visited[j] = true;
            if(dfs(j+1,bucketNum, curSum+nums[j],target, nums, visited)){
                return true;
            }
            visited[j] = false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }

        if (sum % k != 0) {
            return false;
        }

        sort(nums.begin(), nums.end(), greater<int>());

        int target = sum / k;
        vector<bool> visited(nums.size(), false);
        return(dfs(0,k,0,target,nums,visited));
    }
};