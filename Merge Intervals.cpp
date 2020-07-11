class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        if(intervals.size()==0)
            return ans;
        int start=intervals[0][0],end=intervals[0][1];
                        vector<int>temp;
       // cout<<start<<" "<<end<<endl;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                if(intervals[i][1]>=end){
                    end=intervals[i][1];
                }
                else
                    continue;
            } 
            else{
                cout<<"push "<<start<<" "<<end<<endl;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                temp.clear();
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
        return ans;
    }
};
