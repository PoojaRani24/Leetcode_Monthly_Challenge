class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int tmp=matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

        for(int i=0;i<n;i++){
            int l=0,h=n-1;
            while(l<h){
                int tmp=matrix[i][l];
                matrix[i][l] = matrix[i][h];
                matrix[i][h] = tmp;
                l++;
                h--;
            }
        }
    }
};