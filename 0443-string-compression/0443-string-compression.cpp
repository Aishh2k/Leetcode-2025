class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()<2){
            return chars.size();
        }

        int i =0;
        int write = 0;
        while(i<chars.size()){

            char cur = chars[i];
            int count = 0;

            while(i<chars.size() && chars[i] == cur){
                i++;
                count++;
            }
            chars[write] = cur;
            write++;

            if(count>1){
                string s = to_string(count);
                for(char c: s){
                    chars[write] = c;
                    write++;
                }
            }

        }

        return write;

        
    }
};