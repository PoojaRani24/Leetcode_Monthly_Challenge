class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColour = image[sr][sc];
        int n=image.size();
        if(n==0)
            return image;
        int m=image[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));
        q.push({sr,sc});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int,int> currentCell=q.front();
                q.pop();
                int currentX=currentCell.first;
                int currentY=currentCell.second;
                vis[currentX][currentY]=1;
                image[currentX][currentY]=color;
                for(int i=0;i<4;i++){
                    int newX=currentX+dx[i];
                    int newY=currentY+dy[i];
                    if (newX>=0 && newY>=0 && newX<n && newY<m && vis[newX][newY]==0 && image[newX][newY]==originalColour){
                        q.push({newX, newY});
                    }
                }
            }
        }
        return image;
    };
};