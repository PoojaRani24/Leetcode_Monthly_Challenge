class Solution {
public:
    int arrangeCoins(int n) {
        long long int res=sqrt(2*(long)n);
        long long int ans;
        for(long long int i=res;i>0;i--){
            if(((i*(i+1))/2)<=n)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};
