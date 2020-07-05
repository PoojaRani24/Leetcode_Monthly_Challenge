class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        x=x^y;
        while(x){
            if(x&1)
                count++;
            x=x/2;
        }
        return count;
    }
};
