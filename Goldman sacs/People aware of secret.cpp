class Solution {
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        long long sharing = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            long long newSharing = dp[max(0,i-delay)];
            long long forgetting = dp[max(0,i-forget)];

            sharing = (sharing + newSharing - forgetting + mod) % mod;
            dp[i] = sharing % mod;
        }
        long long ans = 0;
        for(int i = n-forget+1; i<=n; i++){
            ans = (ans + dp[i]) % mod;
        }
        return ans%mod;
    }
};