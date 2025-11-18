class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = 0;
        int n = 0;
        int start = 0;

        while(h<haystack.size()){
            if(needle[n] == haystack[h]){
                n++;
            }else{
                h = h-n;
                n = 0;
            }

            if(n == needle.size()){
                return h - needle.size()+1;
            }
            h++;
        }

        return -1;
        
    }
};