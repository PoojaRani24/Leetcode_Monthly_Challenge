class Solution {
public:
    int perfect(int n){
        if(floor(log2(n))==ceil(log2(n)))
            return log2(n);
        else
            return floor(log2(n));
            
    }
    
    vector<int> countBits(int num) {
        int dp[num+1];
        dp[0]=0;
        if(num>=1)
             dp[1]=1;
        if(num>=2)
            dp[2]=1;
        vector<int>ans;
        ans.push_back(0);
        if(num>=1)
            ans.push_back(1);
        if(num>=2)
            ans.push_back(1);
        for(int i=3;i<=num;i++){
            if(floor(log2(i))==ceil(log2(i)))
                dp[i]=1;
            else
                dp[i]=1+dp[i-(int)pow(2,(int)log2(i))];
            ans.push_back(dp[i]);
        }
            return ans;
    }
};
