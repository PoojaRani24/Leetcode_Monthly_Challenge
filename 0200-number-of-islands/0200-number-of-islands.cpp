class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid){
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int X=x+dx[i];
            int Y=y+dy[i];
            if(X>=0 && X<n && Y>=0 && Y<m && grid[X][Y]!='0')
                dfs(X,Y,n,m,grid);
        }
    }
};