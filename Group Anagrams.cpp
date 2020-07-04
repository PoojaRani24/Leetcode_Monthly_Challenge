class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        vector<vector<string>>ans;
        string temp="";
        for(int i=0;i<strs.size();i++){
            temp=strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
            // cout<<m[temp].size();
            temp.clear();
        }
                    // cout<<m.size();
        for(auto i=m.begin();i!=m.end();i++){
           // cout<<typeid(i->second).name();
            ans.push_back(i->second);
        }
       // cout<<endl;
        return ans;
    }
};
