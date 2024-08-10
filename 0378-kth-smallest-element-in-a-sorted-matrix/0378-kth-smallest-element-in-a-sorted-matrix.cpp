class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        return kthSmallestMinHeap(matrix,k);
    }

    int kthSmallestMinHeap(vector<vector<int>>& matrix, int k) {
        int r=matrix.size();
        int c=matrix[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<min(r,k);i++)
            pq.push({matrix[i][0],{i,0}});
        int popedElement=-1;
        while(k--){
            auto it=pq.top();
            popedElement=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            if(col+1<c)
                pq.push({matrix[row][col+1],{row,col+1}});
        }
        return popedElement;
    }
};