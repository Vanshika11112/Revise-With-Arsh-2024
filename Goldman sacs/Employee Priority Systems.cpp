#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(vector<int> v){
        for(int i=0;i<=v.size()-3;i++){
              if(v[i+2]-v[i]<60){
                   return true;
              }
        }
        return false;
  }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
         vector<string>ans;
         unordered_map<string,vector<int>>mp;

         for(auto x:access_times){
              string hours=x[1].substr(0,2);
              string mins=x[1].substr(2,2);
              int totalmins=stoi(hours)*60+stoi(mins);
             mp[x[0]].push_back(totalmins);
         }

         for(auto m:mp){
              if(m.second.size()<3){
                   continue;
              }
              sort(m.second.begin(),m.second.end());

              if(isValid(m.second)){
                 ans.push_back(m.first);
              }
         }
         return ans;
    }
};