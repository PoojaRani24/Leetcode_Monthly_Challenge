class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s= "123456789";
        vector<int>ans;
        int minLen = to_string(low).length();
        int maxLen =  to_string(high).length();
        for(int i=minLen;i<=maxLen;i++){
            for(int j=0;j<=9-i;j++){
                int tmp = stoi(s.substr(j,i));
                if(tmp>=low && tmp<=high)
                    ans.push_back(tmp);
            }
        }
        return ans;
    }
};