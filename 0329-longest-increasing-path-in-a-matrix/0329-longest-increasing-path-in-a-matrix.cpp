class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0)
            return 0;
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(matrix,i,j,dp));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int& x, int& y, vector<vector<int>>& dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(dp[x][y]!=0)
            return dp[x][y];
        int ans=1;
        for(int i=0;i<4;i++){
            int X=x+dx[i];
            int Y=y+dy[i];
            if(X>=0 && Y>=0 && X<n && Y<m && matrix[X][Y]>matrix[x][y]){
                ans=max(ans,1+dfs(matrix,X,Y,dp));
            }
        }
        dp[x][y]=ans;
        return dp[x][y];
    }
};