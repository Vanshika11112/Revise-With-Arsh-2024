class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0; i<nums.size(); i++){
            vector<int> arr;
            int count = 0;
            for(int j=i; j>=0; j--){
                arr.push_back(nums[j]);
                if(nums[j]%p == 0){
                    count++;
                }
                if(count > k){
                    break;
                }
                s.insert(arr);
            }
        }
        return s.size();
    }
};