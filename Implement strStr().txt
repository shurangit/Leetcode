class Solution {
public:
    int strStr(string haystack, string needle) {
        int hsize=haystack.size(), nsize=needle.size();
        if(hsize==0&&nsize==0) return 0;
        if(nsize>hsize) return -1;
        int start;
        for(int i=0;i<=hsize-nsize;i++){
            int j=0;
            while(j<nsize&&haystack[i+j]==needle[j]){
                j++;
            }
            if(j==nsize) return i;
        }
        return -1;
    }
};