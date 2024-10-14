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
    int getImportance(vector<Employee*> employees, int id) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,pair<int,vector<int>>>m;
        for(auto it: employees)
            m[it->id]={it->importance, it->subordinates};
        return resolve(id,m);
    }

    int resolve(int id, unordered_map<int,pair<int,vector<int>>>&m){
       int val = m[id].first;
       for(auto it:m[id].second)
            val+=resolve(it,m);
       return val;
    }
};