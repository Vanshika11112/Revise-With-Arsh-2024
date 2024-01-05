class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
            int hash[n+1]={0};
            vector<int>ans;
            for(int i=0;i<arr.size();i++){
                  hash[arr[i]]++;
            }
            int miss=-1,repeat=-1;
            for(int i=1;i<=n;i++){
                 if(hash[i]==0){
                     miss=i;
                 }
                 if(hash[i]==2){
                     repeat=i;
                 }
            }
            ans.push_back(repeat);
            ans.push_back(miss);
            return ans;
    }
};