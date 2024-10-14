/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,pair<int,vector<int>>>m;
    int getImportance(vector<Employee*> employees, int id) {
        for(auto it: employees)
            m[it->id]={it->importance, it->subordinates};
        return dfs(id);
    }

    int dfs(int id){
       int val = m[id].first;
       for(auto it:m[id].second)
            val+=dfs(it);
       return val;
    }
};