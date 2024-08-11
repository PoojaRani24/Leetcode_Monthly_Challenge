class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>>dp(2501,vector<int>(2501,-1));
        // return lengthOfLISUtil1(nums,0,-1,dp);

        return lengthOfLIS2(nums);
    }

    int lengthOfLISUtil1(vector<int>& nums,int curInd, int prevInd, vector<vector<int>>&dp){
        int n=nums.size();
        if(curInd==n)
            return 0;
        if(dp[curInd][prevInd+1]!=-1)
            return dp[curInd][prevInd+1];
        int canPick = 0;
        if(prevInd==-1 || nums[curInd]>nums[prevInd])
            canPick = 1 + lengthOfLISUtil1(nums,curInd+1,curInd,dp);
        int dontPick = lengthOfLISUtil1(nums,curInd+1,prevInd,dp);
        return dp[curInd][prevInd+1] = max(canPick, dontPick);
    }

    int lengthOfLIS2(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    dp[i]=max(dp[j]+1,dp[i]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};