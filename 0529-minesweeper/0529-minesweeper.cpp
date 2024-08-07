class Solution {
public:
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i=click[0],j=click[1];
        dfs(board,i,j);
        return board;
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        if(isInvalid(board, i, j))
            return;
        
        // Stepped on Mine, game ends
        if(board[i][j]=='M'){
            board[i][j]='X';
            return;
        }

        // Steped on blank space with adjacent mine
        int cnt=hasAdjacentMines(board, i, j);
        if(cnt!=0){
            board[i][j]=cnt+'0';
            return;
        }

        // Steped on blank space with no adjacent mine, recursively unravel adjacent blocks
        board[i][j]='B';
        for(int p=0;p<8;p++){
            int x=i+dx[p];
            int y=j+dy[p];
            dfs(board,x,y);
        }
    }

    int hasAdjacentMines(vector<vector<char>>& board, int i, int j){
        int cnt=0;
        for(int p=0;p<8;p++){
            int x=i+dx[p];
            int y=j+dy[p];
            if(isInvalid(board,x,y))continue;
            if(board[x][y]=='M')
                cnt++;
        }
        return cnt;
    }
    
    bool isInvalid(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || (board[i][j]!='M' && board[i][j]!='E'))
            return true;
        return false;
    }
};