class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int maxLength=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]+1 > dp[i]){
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(dp[i]==dp[j]+1)
                        cnt[i]+=cnt[j];
                }
            }
            maxLength=max(maxLength, dp[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxLength)
                ans+=cnt[i];
        }
        return ans;
    }

};