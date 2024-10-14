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
        unordered_map<int,pair<int,vector<int>>>m;
        for(int i=0;i<employees.size();i++){
            m[employees[i]->id]={employees[i]->importance, employees[i]->subordinates};
        }
        return resolve(id,m);
    }

    int resolve(int id, unordered_map<int,pair<int,vector<int>>>&m){
       int val = m[id].first;
       for(int i=0;i<m[id].second.size();i++){
            val+=resolve(m[id].second[i],m);
       }
       return val;
    }
};