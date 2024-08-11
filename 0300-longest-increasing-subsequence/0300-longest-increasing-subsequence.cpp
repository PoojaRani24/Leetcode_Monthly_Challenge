class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(2501,vector<int>(2501,-1));
        return lengthOfLISUtil(nums,0,-1,dp);
    }
    int lengthOfLISUtil(vector<int>& nums,int curInd, int prevInd, vector<vector<int>>&dp){
        int n=nums.size();
        if(curInd==n)
            return 0;
        if(dp[curInd][prevInd+1]!=-1)
            return dp[curInd][prevInd+1];
        int canPick = 0;
        if(prevInd==-1 || nums[curInd]>nums[prevInd])
            canPick = 1 + lengthOfLISUtil(nums,curInd+1,curInd,dp);
        int dontPick = lengthOfLISUtil(nums,curInd+1,prevInd,dp);
        return dp[curInd][prevInd+1] = max(canPick, dontPick);
    }
};