class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        queue <pair<int,int>> q;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(isWater[i][j] == 0){
                    isWater[i][j] = -1;
                }else{
                    isWater[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        int hill = 0;
        while(!q.empty()){
            int n = q.size();
            for(int k=0; k<n; k++){
                pair<int,int> front = q.front();
                q.pop();
                int i = front.first, j = front.second;
                //top cell
                if(i>0 && isWater[i-1][j] == -1){
                    isWater[i-1][j] = hill + 1;
                    q.push({i-1, j});
                }
            
                //bottom cell
                if ((i < r - 1) && (isWater[i + 1][j] == -1)) {
                    isWater[i + 1][j] = hill + 1;
                    q.push({i + 1, j});
                }
                //left cell
                if (j > 0 && (isWater[i][j - 1] == -1)) {
                    isWater[i][j - 1] = hill + 1;
                    q.push({i, j - 1});
                }

                //right
                if ((j < c - 1) && (isWater[i][j + 1] == -1)) {
                    isWater[i][j + 1] = hill + 1;
                    q.push({i, j+1});
                }
            }
            hill+=1;
        }
        return isWater;
    }
};