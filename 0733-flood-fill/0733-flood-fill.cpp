class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    int nr=0, nc=0;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc])
            return image;
        nr = image.size();
        nc = image[0].size();
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor){
        image[sr][sc] = newColor;
        for(int i=0;i<4;i++){
            int r = sr+dx[i];
            int c = sc+dy[i];
            if(r<0 || c<0 || r>=nr || c>=nc || image[r][c]!=oldColor)
                continue;
            dfs(image, r, c, newColor, oldColor);
        }
    }
};