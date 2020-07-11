class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int start=0,end=n-1;
        for(int i=0;i<n/2;i++){
           // cout<<"layer "<<i<<endl;
            int s=i;
            int e=end-i;
            for(int j=s;j<e;j++){
                int a=matrix[i][j];
                int b=matrix[j][e];
                int c=matrix[e][e-j+i];
                int d=matrix[e-j+i][i];
               // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                matrix[j][e]=a;
                matrix[e][e-j+i]=b;
                matrix[e-j+i][i]=c;
                matrix[i][j]=d;
            }
        }
        return;
    }
};
