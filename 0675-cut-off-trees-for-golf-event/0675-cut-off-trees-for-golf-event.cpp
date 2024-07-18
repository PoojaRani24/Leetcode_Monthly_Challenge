class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int bfs(int& srcX,int& srcY, int& desX, int& desY, int& n, int& m, vector<vector<int>>& forest){
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{srcX,srcY}});
        vis[srcX][srcY]=1;
        while(!q.empty()){
            auto it = q.front();
            int step=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==desX && y==desY)
                return step;
            q.pop();
            for(int i=0;i<4;i++){
                int X=x+dx[i];
                int Y=y+dy[i];
                if(X>=0 && Y>=0 && X<n && Y<m && forest[X][Y]!=0 && !vis[X][Y]){
                    q.push({step+1,{X,Y}});
                    vis[X][Y]=1;
                }
            }
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1)
                    v.push_back({forest[i][j],{i,j}});
            }
        }
        v.push_back({0,{0,0}});
        sort(v.begin(),v.end());
        int totsteps=0,steps=0;
        for(int i=1;i<v.size();i++){
            int srcX=v[i-1].second.first;
            int srcY=v[i-1].second.second;
            int desX=v[i].second.first;
            int desY=v[i].second.second;
            steps=bfs(srcX,srcY,desX,desY,n,m,forest);
            if(steps==-1)
                return -1;
            totsteps+=steps;
        }
        return totsteps;
    }
};