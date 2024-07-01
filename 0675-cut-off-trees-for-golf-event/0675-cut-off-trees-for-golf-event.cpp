class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int cutOffTree(vector<vector<int>>& forest) {
        int n=forest.size();
        int m=forest[0].size();
        vector<pair<int,pair<int,int>>>flatgrid;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]>1)
                    flatgrid.push_back({forest[i][j],{i,j}});
            }
        }
        flatgrid.push_back({0,{0,0}});
        sort(flatgrid.begin(),flatgrid.end());

        int steps=0,totalsteps=0;
        for(int i=0;i<flatgrid.size()-1;i++){
            int srci = flatgrid[i].second.first;
            int srcj = flatgrid[i].second.second;

            int desi = flatgrid[i+1].second.first;
            int desj = flatgrid[i+1].second.second;
            steps=bfs(srci,srcj,desi,desj,forest);
            if(steps==-1){
                return -1;}
            totalsteps+=steps;
        }
        return totalsteps;
    }

    int bfs(int srci, int srcj, int desi, int desj, vector<vector<int>>& forest){
        int n=forest.size();
        int m=forest[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{srci,srcj}});
        vis[srci][srcj]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int curlvl=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==desi && y==desj){
                return curlvl;
            }
            
            for(int i=0;i<4;i++){
                int X=x+dx[i];
                int Y=y+dy[i];
                if(X>=0 && X<n && Y>=0 && Y<m && !vis[X][Y] && forest[X][Y]!=0){
                    vis[X][Y]=1;
                    q.push({curlvl+1,{X,Y}});
                }
            }
        }
        return -1;
    }
};