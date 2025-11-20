class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for (char i : s) {
            count[i - 'a']++;
        }

        vector<int> nums(10, 0);

        nums[0] = count['z' - 'a'];
        nums[8] = count['g' - 'a'];
        nums[6] = count['x' - 'a'];
        nums[2] = count['w' - 'a'];
        nums[4] = count['u' - 'a'];

        nums[1] = count['o' - 'a'] - nums[2] - nums[4] - nums[0];
        nums[3] = count['r' - 'a'] - nums[4] - nums[0];
        nums[5] = count['f' - 'a'] - nums[4];
        nums[7] = count['s' - 'a'] - nums[6];
        nums[9] = count['i' - 'a'] - nums[8] - nums[5]- nums[6];

        string res = "";
        for (int i = 0; i < 10; i++) {
            while (nums[i] > 0) {
                res += to_string(i);
                nums[i]--;
            }
        }

        return res;
    }
};