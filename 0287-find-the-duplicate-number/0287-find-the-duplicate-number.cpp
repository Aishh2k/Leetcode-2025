class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
            cout<<slow<< " : "<<fast <<endl;
        } while(slow != fast);

        slow = 0;
    cout<<endl;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
            cout<<slow<< " : "<<fast <<endl;
        }
        return slow;
        
    }
};
