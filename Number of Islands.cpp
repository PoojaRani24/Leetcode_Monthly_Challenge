class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int a,int b,int r,int c){
        visited[a][b]=1;
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int x=a+row[i];
            int y=b+col[i];
            if((x>=0 && x<r)&&(y>=0 && y<c)&&(grid[x][y]=='1')&&(visited[x][y]==0)){
                dfs(grid,visited,x,y,r,c);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int r=grid.size();
        if(r==0)
            return 0;
        int c=grid[0].size();
        vector<vector<int>>visited(r+1,vector<int>(c+1,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(grid,visited,i,j,r,c);
                }
            }
        }
        return count;
    }
};
