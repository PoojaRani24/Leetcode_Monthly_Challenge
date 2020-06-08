class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0 && floor(log2(n))==ceil(log2(n)))
            return true;
        else
            return false;
    }
};
