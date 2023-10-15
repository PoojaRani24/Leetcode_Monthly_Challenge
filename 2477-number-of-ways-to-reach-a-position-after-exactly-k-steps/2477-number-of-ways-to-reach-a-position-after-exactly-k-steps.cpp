class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        // return numberOfWaysRecursion(startPos,endPos,k);
        vector<vector<int>>dp(30002,vector<int>(1001,-1));
        return numberOfWaysMemoisation(startPos,endPos,k,dp);
        // vector<vector<int>>dp(30001,vector<int>(1001,0));
        // return numberOfWaysTabulation(startPos,endPos,k,dp);
    }

    int numberOfWaysTabulation(int startPos, int endPos, int k,vector<vector<int>>&dp){
        if(k==0 && startPos==endPos)
            return 1;
        if(k<=0)
            return 0;
        if(dp[startPos+1000][k]!=-1)
            return dp[startPos+1000][k];
        dp[startPos+1000][k] = numberOfWaysRecursion(startPos+1,endPos,k-1) + numberOfWaysRecursion(startPos-1,endPos,k-1);
        return dp[startPos+1000][k];
    }

    int numberOfWaysMemoisation(int startPos, int endPos, int k,vector<vector<int>>&dp){
        if(k==0 && startPos==endPos)
            return 1;
        if(k<=0)
            return 0;
        if(dp[startPos+1000][k]!=-1)
            return dp[startPos+1000][k];
        dp[startPos+1000][k] = (numberOfWaysMemoisation(startPos+1,endPos,k-1,dp)%1000000007 + numberOfWaysMemoisation(startPos-1,endPos,k-1,dp)%1000000007)%1000000007;
        return dp[startPos+1000][k];
    }

    int numberOfWaysRecursion(int startPos, int endPos, int k){
        if(k==0 && startPos==endPos)
            return 1;
        if(k<=0)
            return 0;
        return(numberOfWaysRecursion(startPos+1,endPos,k-1) + numberOfWaysRecursion(startPos-1,endPos,k-1));
    }
};