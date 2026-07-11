class Solution {
public:
    int mySqrt(int x) {
        if(x<2)
            return x;
        int left=1, right=x;
        while(left<=right){
            long mid = left+(right-left)/2;
            long sq=mid*mid;
            if(sq == x)
                return mid;
            else if(sq>x)
                right=mid-1;
            else if(sq<x)
                left=mid+1;
        }
        return right;
    }
};