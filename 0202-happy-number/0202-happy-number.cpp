class Solution {
public:
    int get_next(int n){
        int ans=0;
        while(n){
            ans=ans+(n%10)*(n%10);
            n=n/10;
        }
        return ans;
    }

    bool isHappy(int n) {
        int slow=n;
        int fast=get_next(n);
        while(slow!=fast){
            slow=get_next(slow);
            fast=get_next(get_next(fast));
        }
        return slow==1;
    }
};