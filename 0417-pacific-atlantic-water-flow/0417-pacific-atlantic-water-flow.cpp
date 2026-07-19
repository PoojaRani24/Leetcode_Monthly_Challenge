class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>pacific(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
            pacific[0][j]=1;
                
        for(int i=1;i<n;i++)
            pacific[i][0]=1;
        
        for(int j=0;j<m;j++)
            dfs(0,j,pacific,heights);
        for(int i=1;i<n;i++)
            dfs(i,0,pacific,heights);

        vector<vector<int>>atlantic(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
            atlantic[n-1][j]=1;
                
        for(int i=0;i<n-1;i++)
            atlantic[i][m-1]=1;
        
        for(int j=0;j<m;j++)
            dfs(n-1,j,atlantic,heights);
        
        for(int i=0;i<n-1;i++)
            dfs(i,m-1,atlantic,heights);

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

    void dfs(int cr, int cc, vector<vector<int>>& ocean, vector<vector<int>>& heights){
        ocean[cr][cc]=1;
        int tr=heights.size();
        int tc=heights[0].size();
        for(int i=0;i<4;i++){
            int r=cr+dx[i];
            int c=cc+dy[i];
            if(r<0 || c<0 || r>=tr || c>=tc || ocean[r][c]!=-1)
                continue;
            else if(heights[r][c]<heights[cr][cc])
                continue;
            else
                dfs(r,c,ocean,heights);
        }
    }
};