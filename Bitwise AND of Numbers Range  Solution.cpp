class Solution {
public:
    int msb(int a){
        int count=0;
        while(a){
            a=a/2;
            count++;
        }
        return count-1;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        int res=0;
        while(m && n){
            int msb_m=msb(m);
            int msb_n=msb(n);
            if(msb_m!=msb_n)
                break;
            res+=pow(2,msb_m);
            m=m-pow(2,msb_m);
            n=n-pow(2,msb_m);
        }
        return res;
    }
};
