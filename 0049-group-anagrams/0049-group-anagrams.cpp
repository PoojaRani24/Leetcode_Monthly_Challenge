class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++){
            string sorted_str = strs[i];
            sort(sorted_str.begin(),sorted_str.end());
            m[sorted_str].push_back(strs[i]);
        }

        vector<vector<string>>ans;
        for(auto it=m.begin();it!=m.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};