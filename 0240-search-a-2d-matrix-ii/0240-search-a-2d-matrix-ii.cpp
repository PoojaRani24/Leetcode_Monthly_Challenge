class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int i=r-1,j=0;
        while(i>=0 && j<c){
            if(matrix[i][j]>target)
                i--;
            else if(matrix[i][j]<target)
                j++;
            else
                return true;
        }
        return false;
    }
};