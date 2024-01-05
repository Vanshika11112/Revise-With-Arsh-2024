class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n = S.length();
        string ans = "";
        stack<int> st;
        for(int i=0; i<=n; i++){
            st.push(i+1);
            if(S[i] == 'I' || i == n){
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};