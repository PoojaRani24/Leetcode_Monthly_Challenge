class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
            return n;
        int last_second=1;
        int last=2;
        for(int i=3;i<=n;i++){
            int ans=last+last_second;
            last_second=last;
            last=ans;

        }
        return last;
    }
};