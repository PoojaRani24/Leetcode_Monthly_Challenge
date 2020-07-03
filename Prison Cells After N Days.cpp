class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N=(N%14==0)?14:N%14;
        vector<int>temp(8,0);
        while(N--){
            for(int i=1;i<=6;i++){
                if((cells[i-1]==0 && cells[i+1]==0) || (cells[i-1]==1 && cells[i+1]==1))
                    temp[i]=1;
                else
                    temp[i]=0;
            }
            cells=temp;
        }
        return cells;
    }
};
