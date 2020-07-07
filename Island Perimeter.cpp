class Solution {
public:
    int neigh(vector<vector<int>>& grid,int a,int b){
        int count=0;
        int r=grid.size();
        int c=grid[0].size();
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int x=a+row[i];
            int y=b+col[i];
            if(x>=0 && x<r && y>=0 && y<c && grid[x][y]==1)
                count++;
        }
        return count;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(r==0)
            return 0;
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    ans+=(4-neigh(grid,i,j));
                }
            }
        }
        return ans;
    }
};
